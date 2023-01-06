#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "palindrome.h"
using std::cin; using std::cout; using std::endl;
using std::string; using std::ifstream; using std::getline;
using std::vector;

int main() {
    // For some reason the local path didn't seem to work. Not sure where it is set to by default.
    string path = "/Users/danielbulhosa/CLionProjects/Accelerated C++ Exercises/exercise5-10/words.txt";
    ifstream dictionary(path); // ifstream is input filestream, ofstream is output filestream.
    string line;
    vector<string> palindromes;
    int index = 0, maxindex = 0;
    string::size_type length = 0, maxlength = 0;

    while(getline(dictionary, line)){
        if(is_palindrome(line)){
            palindromes.push_back(line);
            length = line.size();

            if(maxlength < length){
                maxindex = index;
                maxlength = length;
            }
            ++index;
        }
    }

    dictionary.close();
    string longest_palindrome = palindromes[maxindex];
    cout << "The longest palindrome is: " << longest_palindrome << endl;
    // Returns `kinnikinnik`, which is not the longest overall but likely the longest in this small dictionary file.

    return 0;
}
