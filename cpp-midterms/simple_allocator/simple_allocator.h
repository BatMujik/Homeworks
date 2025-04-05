#ifndef SIMPLE_ALLOCATOR_H
#define SIMPLE_ALLOCATOR_H

#include <cstddef>
#include <cstdlib>
#include <new>

template <typename T>
class SimpleAllocator
{
public:
    T *allocate(std::size_t n)
    {
        if (n == 0)
            return nullptr;
        T *ptr = static_cast<T *>(std::malloc(n * sizeof(T)));
        if (!ptr)
            throw std::bad_alloc();
        return ptr;
    }

    void deallocate(T *ptr, std::size_t n)
    {
        if (ptr)
        {
            std::free(ptr);
        }
    }

    template <typename... Args>
    void construct(T *ptr, Args &&...args)
    {
        new (ptr) T(std::forward<Args>(args)...);
    }

    void destroy(T *ptr)
    {
        ptr->~T();
    }
};

#endif
