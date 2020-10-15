#include "allocator.hpp"

Allocator::Allocator(): buffer(nullptr), buf_size(0), offset(0) {}

Allocator::~Allocator()
{
    delete[] buffer;
}

void Allocator::makeAllocator(size_t maxsize)
{
    buffer = new char[maxsize];
    buf_size = maxsize;
}

char* Allocator::alloc(size_t size)
{
    if (size + offset < buf_size)
    {
        char* result = buffer + offset;
        offset += size;
        return result;
    } else {
        return nullptr;
    }
}

void Allocator::reset()
{
    offset = 0;
}