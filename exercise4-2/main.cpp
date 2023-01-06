#include <iostream>
#include <iomanip>
#include <string>
using std::cout; using std::cin;
using std::endl; using std::setw;
using std::string; using std::to_string;

int main() {
    int padding = 9; // Minimum amount of padding needed to hold squares up to 100^2.
    for(int i=1; i <= 100; ++i){
        int square = i*i;
        string::size_type size = to_string(i).size();

        // Correct for the growth of the number on the left column by `size`
        cout << i << setw(padding - size)<< square << endl;
    }
}
