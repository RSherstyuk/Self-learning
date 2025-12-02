#include <iostream>
#include "lru.h"

int main() {
    lruCache cache(2); 
    
    cache.put(1, 10);
    cache.put(2, 20);

    std::cout << "Get 1: " << cache.get(1) << std::endl; 

    cache.put(3, 30);  
    std::cout << "Put 3 (evicts 2)" << std::endl;

    std::cout << "Get 2: " << cache.get(2) << std::endl; 

    return 0;
}


