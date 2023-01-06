// Same as exercise2-0 but with comments removed. Current comments highlight changes made.
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main() {

    const int pad = 2;
    const string trail_space(pad, ' ');

    cout << "Please enter your name: " << endl;
    string name;
    cin >> name;
    string greeting = "Hello, " + name + "!";
    const string::size_type cols = greeting.size() + 2 * pad + 2;
    const int rows = 1 + 2 * pad + 2;
    const string space(cols - 2, ' '); // Create a string containing all spaces needed per line.
    const string star_row(cols, '*'); // Create a string containing all * needed for top and bottom rows.

    cout << endl;

    for (int r = 0; r != rows; ++r){
        string::size_type c = 0;

        while (c != cols){
            // Went ahead and re-wrote so top and bottom rows are written all at once.
            if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1){
                if (r == 0 || r == rows - 1){
                    cout << star_row;
                    c += star_row.size();
                }
                else{
                    cout << "*";
                    ++c;
                }
            }
            else {
                // Make if condition independent of column: Means entire rows are written at once.
                if (r == pad + 1){
                    cout << trail_space + greeting + trail_space; // Add trailing space directly to greeting.
                    c += greeting.size() + 2 * trail_space.size(); // Account for added trailing space in column count.
                }
                else{
                    // Create a statement that adds all spaces at ones and increments c appropriately.
                    cout << space;
                    c += space.size();
                }
            }
        }

        cout << endl;
    }

    return 0;
}
