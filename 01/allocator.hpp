#pragma once
#include <cstddef>

class Allocator
{
    char* buffer;
    size_t buf_size;
    size_t offset;
public:
    Allocator();
    ~Allocator();
    void makeAllocator(size_t maxSize);
    char* alloc(size_t size);
    void reset();
};