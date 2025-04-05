#include <iostream>
#include "pool_allocator.h"

struct MyObject {
    int x;
    float y;

    MyObject(int x, float y) : x(x), y(y) {}
};

int main() {
    const size_t blockSize = sizeof(MyObject);
    const size_t blockCount = 10;

    PoolAllocator allocator(blockSize, blockCount);

    // Allocate objects
    MyObject* obj1 = new (allocator.allocate()) MyObject(1, 1.1f);
    MyObject* obj2 = new (allocator.allocate()) MyObject(2, 2.2f);

    std::cout << "Object 1: x = " << obj1->x << ", y = " << obj1->y << std::endl;
    std::cout << "Object 2: x = " << obj2->x << ", y = " << obj2->y << std::endl;

    // Deallocate objects
    obj1->~MyObject();
    allocator.deallocate(obj1);

    obj2->~MyObject();
    allocator.deallocate(obj2);

    return 0;
}
