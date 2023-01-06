#include <iostream>
#include <cctype>
#include <vector>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::islower; using std::isupper; using std::string;
using std::vector;

int main() {
    cout << "Please enter some words to test: " << endl;
    string word;
    vector<string> all_lower;
    vector<string> some_upper;

    while(cin >> word){
        bool has_upper = false;
        for(char c: word){
            if(isupper(c)){
                some_upper.push_back(word);
                has_upper = true;
                break;
            }
        }
        if(!has_upper){
            all_lower.push_back(word);
        }
    }

    cout << "The words without any upper case letters were: " << endl;
    for(const string& w: all_lower){
        cout << w << endl;
    }
    cout << "The words with some upper case letters were: " << endl;
    for(const string& w: some_upper){
        cout << w << endl;
    }

}
