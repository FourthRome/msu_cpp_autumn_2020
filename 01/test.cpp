#include <iostream>
#include <cstring>
#include <cassert>
#include "allocator.hpp"

void DefaultWorkTest()
{
    // Create objects
    Allocator test_allocator;
    std::string test_str = "Hello, world!";
    
    // Initialize allocator's memory
    test_allocator.makeAllocator(test_str.size());
    char* buf = test_allocator.alloc(test_str.size());
    std::strncpy(buf, test_str.c_str(), test_str.size());

    // Verify allocator's contents
    assert(strncmp(buf, test_str.c_str(), test_str.size()) == 0);
}

void ResetTest()
{
    // Create objects
    Allocator test_allocator;
    std::string test_str = "Hello, world!";
    
    // Initialize allocator's memory
    test_allocator.makeAllocator(test_str.size());
    char* buf = test_allocator.alloc(test_str.size());
    strncpy(buf, test_str.c_str(), test_str.size());

    // Reset and make sure the memory is the same as before
    test_allocator.reset();
    char* buf_2 = test_allocator.alloc(test_str.size());
    assert(buf == buf_2);
    assert(strcmp(buf, buf_2) == 0);
}

void MakeAllocatorTest()
{
}

int main()
{
    std::cout << "Starting testing:" << std::endl;
    DefaultWorkTest();
    ResetTest();

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}
