#include "pool_allocator.h"
#include <cstdlib>
#include <cstring>

PoolAllocator::PoolAllocator(size_t blockSize, size_t blockCount)
    : blockSize(blockSize), poolSize(blockSize * blockCount), freeList(nullptr) {
    pool = std::malloc(poolSize);
    if (!pool) {
        throw std::bad_alloc();
    }

    // Initialize the free list
    char* current = static_cast<char*>(pool);
    for (size_t i = 0; i < blockCount; ++i) {
        Block* block = reinterpret_cast<Block*>(current);
        block->next = freeList;
        freeList = block;
        current += blockSize;
    }
}

PoolAllocator::~PoolAllocator() {
    std::free(pool);
}

void* PoolAllocator::allocate() {
    if (!freeList) {
        throw std::bad_alloc();
    }

    Block* block = freeList;
    freeList = freeList->next;
    return block;
}

void PoolAllocator::deallocate(void* ptr) {
    Block* block = static_cast<Block*>(ptr);
    block->next = freeList;
    freeList = block;
}
