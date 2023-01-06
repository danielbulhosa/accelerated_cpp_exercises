#include <iostream>
#include <string>
#include <vector>
#include "center.h"

using std::vector; using std::string; using std::getline;
using std::cin; using std::cout; using std::endl;

int main() {
    cout << "Enter separate lines of text to be centered followed by the EOF symbol: " << endl;
    vector<string> lines;
    string line;

    while(getline(cin, line)){
        lines.push_back(line);
    }

    vector<string> centered_lines = center(lines);

    for(const string& centered_line: centered_lines){
        cout << centered_line << endl;
    }
}
