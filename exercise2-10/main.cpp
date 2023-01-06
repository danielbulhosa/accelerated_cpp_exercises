#include <iostream>

int main() {
    int k = 0;
    while (k != 10){
        // Here std is used to specify that within this scope cout refers to std::cout.
        // Any time cout is referenced then the program will assume that the name lives in the namespace std.
        using std::cout;
        cout << "*";
        ++k;
    }
    // Here std is used to state which namepsace cout and endl are in so they can be found.
    // If not specified the program won't be able to find these names.
    std::cout << std::endl;
    return 0;
}
