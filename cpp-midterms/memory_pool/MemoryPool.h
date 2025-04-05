#ifndef MEMORYPOOL_H
#define MEMORYPOOL_H

#include <cstddef>
#include <vector>

class MemoryPool
{
public:
    MemoryPool(size_t blockSize, size_t blockCount);
    ~MemoryPool();

    void *allocate();
    void deallocate(void *ptr);

private:
    size_t blockSize;
    size_t blockCount;
    std::vector<void *> freeBlocks;
    void *pool;
};

#endif
