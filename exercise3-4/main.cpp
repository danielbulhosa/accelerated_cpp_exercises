#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout; using std::cin; using std::endl;
using std::string; using std::vector; using std::sort;

int main() {
    cout << "Please enter a list of words: " << endl;
    string word;
    vector<int> word_lenghts;

    while(cin >> word){
        word_lenghts.push_back(word.size()); // We can get the size of a string with the size method.
    }

    sort(word_lenghts.begin(), word_lenghts.end());

    cout << "The shortest word had length " << word_lenghts[0] <<
            " and the longest word had length " << word_lenghts[word_lenghts.size() - 1] << endl;

    return 0;
}
