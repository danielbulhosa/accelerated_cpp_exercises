#include <iostream>
#include <numeric>
#include <vector>
#include <string>

using std::vector; using std::string; using std::cin;
using std::cout; using std::endl; using std::getline;
using std::accumulate;

int main() {
    cout << "Please enter a sequence of strings separated by new lines: " << endl;
    vector<string> lines;
    string line;

    while(getline(cin, line)){
        lines.push_back(line);
    }

    // Note we needed to create an actual string, not a char sequence which
    // is what we get when we use "" char sequences. We had to use the string
    // constructor to get the correct type! We create an empty string.
    // It seems then all we need to use `accumulate` is work with a class
    // that defines the `+` operator.
    string concat = accumulate(lines.begin(), lines.end(), string());

    cout << "The concatenated string is: " << concat << endl;

    return 0;
}
