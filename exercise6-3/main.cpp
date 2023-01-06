#include <iostream>
#include<vector>
#include <algorithm>
using std::vector; using std::copy;
using std::cout; using std::cin; using std::endl;

int main() {
    // Creates a vector with the integers in the range [10, 100)
    // WRONG: More like string(n, x), it creates a vector with the value x copied n times.
    vector<int> u(10, 100);
    cout << "The values in the vector `u` are: " << endl;
    for(int value: u){
        cout << value << endl;
    }
    cout << endl << "The number of values in `u` is: " << u.size() << endl;
    vector<int> v;
    // Copies values from u into v BUT FAILS TO ALLOCATE v so it leads to memory leak!
    // In fact before we can leak the memory the function throws a bad access error.
    // See: https://www.xspdf.com/resolution/52545141.html
    copy(u.begin(), u.end(), v.begin());

    // Program fails before getting here.
    cout << "Outputs: " << endl;
    cout << v.empty() << endl;
    cout << u.empty() << endl;
}
