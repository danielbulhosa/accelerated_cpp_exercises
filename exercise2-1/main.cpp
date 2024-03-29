// Same as exercise2-0 but with comments removed. Current comments highlight changes made.
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main() {

    const int pad = 0; // Change program here to eliminate separation from the frame.

    cout << "Please enter your name: " << endl;
    string name;
    cin >> name;
    string greeting = "Hello, " + name + "!";
    const string::size_type cols = greeting.size() + 2 * pad + 2;
    const int rows = 1 + 2 * pad + 2;

    cout << endl;

    for (int r = 0; r != rows; ++r){
        string::size_type c = 0;

        while (c != cols){
            if (r == pad + 1 && c == pad + 1){
                cout << greeting;
                c += greeting.size();
            }
            else{
                if (r == 0 || r == rows - 1 || c == 0 || c == cols -1)
                    cout << "*";
                else
                    cout << " ";
                ++c;
            }

        }

        cout << endl;
    }

    return 0;
}
