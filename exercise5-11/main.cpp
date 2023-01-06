#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "ascenders.h"

using std::ifstream; using std::getline; using std::string; using std::vector;
using std::cin; using std::cout; using std::endl;

int main() {
    ifstream dictionary("/Users/danielbulhosa/CLionProjects/Accelerated C++ Exercises/exercise5-11/words.txt");
    string line;
    vector<string> neithers;
    string::size_type length = 0, maxlength = 0;
    int index = 0, maxindex = 0;

    while(getline(dictionary, line)){
        if(has_neither(line)){
            neithers.push_back(line);
            length = line.size();
            if(length > maxlength){
                maxindex = index;
                maxlength = length;
            }
            ++index;
        }
    }

    cout << "The longest word without any ascenders or descenders is: " << neithers[maxindex];

    return 0;
}
