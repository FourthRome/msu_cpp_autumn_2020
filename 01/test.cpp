#include <iostream>
#include <cstring>
#include "allocator.hpp"

void DefaultWorkTest()
{
    Allocator test_allocator;
    test_allocator.makeAllocator(14);

    std::string test_str = "Hello, world!";
    char* buf = test_allocator.alloc(test_str.size());
    strncpy(buf, test_str.c_str(), test_str.size());
    std::cout << buf << std::endl;
}

int main()
{
    std::cout << "Starting testing:" << std::endl;
    DefaultWorkTest();
    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}
