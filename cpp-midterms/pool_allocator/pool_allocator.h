#ifndef POOL_ALLOCATOR_H
#define POOL_ALLOCATOR_H

#include <cstddef>
#include <stdexcept>

class PoolAllocator {
private:
    struct Block {
        Block* next;
    };

    Block* freeList;
    void* pool;
    size_t blockSize;
    size_t poolSize;

public:
    PoolAllocator(size_t blockSize, size_t blockCount);
    ~PoolAllocator();

    void* allocate();
    void deallocate(void* ptr);

    // Disable copy and assignment
    PoolAllocator(const PoolAllocator&) = delete;
    PoolAllocator& operator=(const PoolAllocator&) = delete;
};

#endif // POOL_ALLOCATOR_H
