#include <iostream>
#include "MinHeap.h"
#include <assert.h>
#include "Clan.h"

using namespace std;

int main() {
    Clan tigers(2);
    Clan bunnies(4);
    Clan lions(10);
    Clan giraffes(8);
    Clan mouses(12);
    Clan cats(5);
    Clan dogs(1);
    Clan** values = new Clan*[7];
    values[0] = &tigers;
    values[1] = &bunnies;
    values[2] = &lions;
    values[3] = &giraffes;
    values[4] = &mouses;
    values[5] = &cats;
    values[6] = &dogs;
    MinHeap test(values, 7);
    assert(test.getFullSize() == 14);
    assert(test.getMin()->getClanID() == 1);
    assert(test.getCurrentSize() == 7);
    test.deleteMin();
    assert(test.getMin()->getClanID() == 2);
    test.deleteMin();
    assert(test.getCurrentSize() == 5);
    Clan yanshufs(3);
    test.insert(&yanshufs);
    assert(test.getCurrentSize() == 6);
    assert(test.getMin()->getClanID() == 3);
    test.deleteMin();
    assert(test.getMin()->getClanID() == 4);
    test.deleteMin();
    assert(test.getMin()->getClanID() == 5);
    test.deleteMin();
    assert(test.getMin()->getClanID() == 8);
    test.deleteMin();
    assert(test.getCurrentSize() == 2);
    assert(test.getFullSize() == 14);
    Clan humans1(100);
    Clan humans2(101);
    Clan humans3(102);
    Clan humans4(103);
    Clan humans5(104);
    Clan humans6(105);
    Clan humans7(106);
    Clan humans8(107);
    Clan humans9(108);
    Clan humans10(109);
    Clan humans11(110);
    Clan humans12(111);
    Clan humans13(112);
    test.insert(&humans1);
    test.insert(&humans2);
    test.insert(&humans3);
    test.insert(&humans4);
    test.insert(&humans5);
    test.insert(&humans6);
    test.insert(&humans7);
    test.insert(&humans8);
    test.insert(&humans9);
    test.insert(&humans10);
    test.insert(&humans11);
    test.insert(&humans12);
    test.insert(&humans13);
    assert(test.getFullSize() == 28);
    assert(test.getCurrentSize() == 15);
    test.deleteMin();
    test.deleteMin();
    assert(test.getMin()->getClanID() == 100);
    test.deleteMin();
    assert(test.getMin()->getClanID() == 101);
    test.decreaseKey(8, 99);
    assert(test.getMin()->getClanID() == 99);
    test.decreaseKey(8, 200);
    assert(test.getMin()->getClanID() == 99);
    test.decreaseKey(1, 200);
    assert(test.getMin()->getClanID() == 99);
    test.deleteMin();
    assert(test.getMin()->getClanID() == 101);

    return 0;
}

