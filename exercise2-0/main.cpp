// Got the program all correct below except for a couple of small errors, all from memory! :D
#include <iostream>
#include <string>

// These specify which namespace to use for each of these names so we don't have to reference them again
using std::cin;
using std::cout;
using std::string;
using std::endl;

int main() {

    const int pad = 1; // We define this in our program as a parameter

    cout << "Please enter your name: " << endl;
    string name;  // Declare string variable
    cin >> name;
    string greeting = "Hello, " + name + "!"; // Note that this works because one operand on the left is a string
    const string::size_type cols = greeting.size() + 2 * pad + 2; // Twice the number of padding, left and right, plus two end cols at each end
    const int rows = 1 + 2 * pad + 2; // Single line for message itself

    cout << endl;

    for (int r = 0; r != rows; ++r){
        string::size_type c = 0;  // Forgot to use string::size_type, though we used int and it worked fine!

        while (c != cols){
            if (r == pad + 1 && c == pad + 1){
                cout << greeting;
                c += greeting.size();
            }
            else{
                if (r == 0 || r == rows - 1 || c == 0 || c == cols -1)
                    cout << "*"; // Forgot that since statement single line, don't need brackets!
                else
                    cout << " "; // Forgot that since statement single line, don't need brackets!
                ++c;  // Forgot that we can share the increment across if-else case since its the same.
            }

        }

        cout << endl;
    }

    return 0;
}
