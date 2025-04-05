#include "simple_allocator.h"
#include <iostream>
#include <string>

struct TestStruct
{
    int id;
    std::string name;

    TestStruct(int id, const std::string &name) : id(id), name(name)
    {
        std::cout << "Constructed TestStruct: " << id << ", " << name << std::endl;
    }

    ~TestStruct()
    {
        std::cout << "Destroyed TestStruct: " << id << ", " << name << std::endl;
    }
};

int main()
{
    SimpleAllocator<TestStruct> allocator;

    TestStruct *ptr = allocator.allocate(3);

    allocator.construct(&ptr[0], 1, "Alice");
    allocator.construct(&ptr[1], 2, "Bob");
    allocator.construct(&ptr[2], 3, "Charlie");

    std::cout << "Object 1: " << ptr[0].id << ", " << ptr[0].name << std::endl;
    std::cout << "Object 2: " << ptr[1].id << ", " << ptr[1].name << std::endl;
    std::cout << "Object 3: " << ptr[2].id << ", " << ptr[2].name << std::endl;

    allocator.destroy(&ptr[0]);
    allocator.destroy(&ptr[1]);
    allocator.destroy(&ptr[2]);

    allocator.deallocate(ptr, 3);

    return 0;
}
