// Same as exercise2-0 but with comments removed. Current comments highlight changes made.
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main() {

    // We add a new pad variable and rename the old one. All pad references regarding
    // rows are changed to top_pad and all padding regarding columns is changed to side_pad.
    const int top_pad = 1;
    const int side_pad = 5;

    cout << "Please enter your name: " << endl;
    string name;
    cin >> name;
    string greeting = "Hello, " + name + "!";
    const string::size_type cols = greeting.size() + 2 * side_pad + 2;
    const int rows = 1 + 2 * top_pad + 2;

    cout << endl;

    for (int r = 0; r != rows; ++r){
        string::size_type c = 0;

        while (c != cols){
            if (r == top_pad + 1 && c == side_pad + 1){
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
