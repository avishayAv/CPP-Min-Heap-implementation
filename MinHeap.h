#ifndef WET2_MINHEAP_H
#define WET2_MINHEAP_H

#include <iostream>
#include <ostream>
#include "Clan.h"

class MinHeap   {
private:
    Clan** array;
    int current_size;
    int full_size;

    /*
     * JOB : siftDown algorithm implementation. (Recursive)
     */
    void siftDown(int i)    {
        int left_son = 2*i+1;
        int right_son = 2*i+2;
        int minimum = i;
        if (left_son < this->current_size)
            if (this->array[left_son]->getClanID() < this->array[i]->getClanID())
                minimum = left_son;
        if (right_son < this->current_size)
            if (this->array[right_son]->getClanID() < this->array[minimum]->getClanID())
                minimum = right_son;
        if (minimum != i)   {
            this->array[i]->setMinLocation(minimum);
            this->array[minimum]->setMinLocation(i);
            swap(&this->array[i], &this->array[minimum]);
            siftDown(minimum);
        }
    }

    /*
     * JOB : swap two elements in the array.
     */
    void swap(Clan **x, Clan **y)   {
        Clan* temp = *x;
        *x = *y;
        *y = temp;
    }

public:
    MinHeap(){};

    /*
     * JOB : creates new heap with size as full_size.
     * - variables initiallization.
     * - copy every value from input array to the heap
     * - for every number in the tree which is not a leave - sift down
     * in the end of the process we will get minHeap.
     */
    MinHeap(Clan** values, int size) {
        this->full_size = 2*size;
        this->array = new Clan*[2*size];
        this->current_size = size;
        for (int i=0; i<size; i++)  {
            this->array[i] = values[i];
        }
        for (int i=size-1; i>=0; i--)   {
            siftDown(i);
        }
        for (int j = 0; j < this->current_size; ++j) {
            this->array[j]->setMinLocation(j);
        }
    };
	~MinHeap() {
		delete[] this->array;
	}

    /*
     * JOB : decreasing a key of a certain index.
     * if the new value is bigger, do nothing.
     */
    void decreaseKey(int i, int value)  {
        if (array[i]->getClanID() <= value)   {
            return;
        }
        array[i]->setClanId(value);
        while (i!=0 && array[(i-1)/2]->getClanID() > array[i]->getClanID())   {
            this->array[i]->setMinLocation(((i-1)/2));
            this->array[((i-1)/2)]->setMinLocation(i);
            swap(&array[i], &array[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    /*
     * JOB : insert new struct to minHeap.
     * #1 - when reaching end of array - increment array.
     * #2 - insert new data
     * #3 - use siftUp algorithm from new leave to the root.
     */
    void insert(Clan* value)  {
        if (this->current_size == (this->full_size - 1))    {
            this->full_size = 2*this->full_size;
            Clan** bigger = new Clan*[2*this->full_size];
            for (int i=0; i<this->current_size;i++)
                bigger[i] = this->array[i];
            Clan** temp = this->array;
            this->array = bigger;
            delete(temp);
        }
        this->current_size++;
        int place = this->current_size - 1;
        array[place] = value;
        array[place]->setMinLocation(place);
        while(place!=0 && array[(place-1)/2]->getClanID() > array[place]->getClanID())  {
            this->array[place]->setMinLocation(((place-1)/2));
            this->array[((place-1)/2)]->setMinLocation(place);
            swap(&this->array[place], &this->array[(place-1)/2]);
            place = (place-1)/2;
        }
    }

    /*
     * JOB : get the minimum number in the heap.
     * For an empty heap - return NULL.
     */
    Clan* getMin()    {
        if (this->current_size == 0)
            return NULL;
        return array[0];
    }

    /*
     * JOB : delete the minimum key in minimum heap
     * #1 - replace it with the most left leave
     * #2 - delete most left tree
     * #3 - use sift down algorithm for the new root
     */
    void deleteMin()    {
        if (this->current_size <= 0)
            return;
        //Clan* root = this->array[0];
		array[0]->setMinLocation(-1);
        this->array[0] = this->array[current_size-1];
		array[0]->setMinLocation(0);
        this->current_size--;
        siftDown(0);
    }

    int getCurrentSize()    {
        return this->current_size;
    }

    int getFullSize()    {
        return this->full_size;
    }
	

};

#endif //WET2_MINHEAP_H
