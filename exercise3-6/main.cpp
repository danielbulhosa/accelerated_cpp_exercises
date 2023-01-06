#include <iostream>
using std::cin; using std::cout; using std::endl;

// We write a simpler program that computes the average of a list of numbers input.
int main() {
    cout << "Please enter a sequence of numbers: " << endl;
    double input;
    int count = 0;
    double sum = 0.0;

    while(cin >> input){
        sum += input;
        ++count;
    }

    // We add this handler to deal with the zero count case.
    // Note that we could have also manually returned a number
    // or something else like NaN.
    if(count == 0){
        cout << "At least one number must be entered. Please try again!";
        return 1;
    }

    // Returns nan when we divide 0 by 0. If we hard code
    // sum to 1 and let count be zero we get `Exception: EXC_ARITHMETIC (code=EXC_I386_DIV, subcode=0x0)`.
    // Thus the return even depends of the combination of numbers being divided.
    // We expect this may have been different in a different computer.
    cout << "The average of the numbers is: " << sum/count << endl;

    return 0;
}
