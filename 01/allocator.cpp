#include "allocator.hpp"

// Default constructor
Allocator::Allocator(): buffer(nullptr), buf_size(0), offset(0) {}

// Destructor, works safely in every scenario
Allocator::~Allocator()
{
    delete[] buffer;
}

// Why isn't this part of the constructor? Looks completely out of sense
void Allocator::makeAllocator(size_t maxsize)
{
    // TODO: check if maxsize is a reasonable amount of memory 

    // Allow reusability, but the data will be gone
    if (buffer != nullptr) { delete[] buffer; }

    buffer = new char[maxsize];
    buf_size = maxsize;
}

// Get some memory from the allocator
char* Allocator::alloc(size_t size)
{
    if (buffer != nullptr && (size + offset) < buf_size)
    {
        // TODO: check if adding size_t to a pointer is a good idea
        // TODO: check if overflow is possible here
        char* result = buffer + offset;
        offset += size;
        return result;
    }
    else { return nullptr; }
}

// Reuse allocator's memory
void Allocator::reset()
{
    // This will even work on a non-initalized allocator,
    // which is not a good thing. However, I thought for
    // the purpose of the task it will be inappropriate to
    // raise an exception here. 
    offset = 0;
}