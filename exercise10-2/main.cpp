#include <iostream>
#include <vector>
#include "median.h"

int main() {
    std::vector<int> v = {2, 3, 5, 4, 1};
    int array[] = {2, 3, 5, 4, 1};
    typedef int arrayint[5];
    /*
     * Note that getting this to be polymorphic requires
     * rewriting the median function to work on iterators.
     * This is just how the algorithms library is designed as
     * well. This is where we drew our inspiration.
     */
    int med = median(v.begin(), v.end());
    int med2 = median(array, array + 5);

    std::cout << med << std::endl;
    std::cout << med2 << std::endl;

    std::cout << std::endl;
    for(int x: v){
        std::cout << x << std::endl;
    }
    std::cout << std::endl;
    for(int x: array){
        std::cout << x << std::endl;
    }
    // The order was preserved!

    return 0;
}
