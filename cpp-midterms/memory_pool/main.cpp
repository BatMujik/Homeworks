#include "MemoryPool.h"
#include <iostream>

int main()
{
    try
    {
        MemoryPool pool(32, 10);

        void *block1 = pool.allocate();
        void *block2 = pool.allocate();

        std::cout << "Allocated two blocks." << std::endl;

        pool.deallocate(block1);
        pool.deallocate(block2);

        std::cout << "Deallocated two blocks." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
