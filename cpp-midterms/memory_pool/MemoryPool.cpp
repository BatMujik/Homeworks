#include "MemoryPool.h"
#include <cstdlib>
#include <stdexcept>

MemoryPool::MemoryPool(size_t blockSize, size_t blockCount)
    : blockSize(blockSize), blockCount(blockCount)
{
    pool = std::malloc(blockSize * blockCount);
    if (!pool)
    {
        throw std::bad_alloc();
    }

    for (size_t i = 0; i < blockCount; ++i)
    {
        freeBlocks.push_back(static_cast<char *>(pool) + i * blockSize);
    }
}

MemoryPool::~MemoryPool()
{
    std::free(pool);
}

void *MemoryPool::allocate()
{
    if (freeBlocks.empty())
    {
        throw std::bad_alloc();
    }
    void *block = freeBlocks.back();
    freeBlocks.pop_back();
    return block;
}

void MemoryPool::deallocate(void *ptr)
{
    freeBlocks.push_back(ptr);
}
