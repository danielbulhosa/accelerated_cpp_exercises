#include <iostream>
#include <string>
#include <vector>
#include "frame.h"
#include "hcat.h"

using std::vector; using std::string;
using std::cin; using std::cout; using std::endl;
using std::getline;

int main() {
    cout << "Please enter a sequence of strings separated by new lines: " << endl;
    vector<string> lines;
    string line;

    while(getline(cin, line)){
        lines.push_back(line);
    }

    vector<string> framed_lines = frame(lines);
    vector<string> concat_lines = hcat(lines, framed_lines);

    for(const string& framed_line: framed_lines){
        cout << framed_line << endl;
    }

    cout << endl;

    for(const string& concat_line: concat_lines){
        cout << concat_line << endl;
    }

    return 0;
}
