#include <iostream>
#include <vector>
#include <string>
using std::cout; using std::cin; using std::endl;
using std::vector; using std::string;

int main() {
    // Just do a while loop with a for loop in it. It'll be O(N^2)
    // but we can't do better until we know how to do hashes in C++.
    cout << "Enter a sequence of words separated by spaces: " << endl;

    vector<string> strings;
    vector<int> counts;
    string word;

    while(cin >> word){
        bool word_exists = false;
        for (int i = 0; i != strings.size(); ++i) {
            string stored_word = strings[i];
            if (stored_word == word) {
                counts[i] += 1;
                word_exists = true;
                break; // Same word as Python for this purpose
            }
        }
        if (!word_exists) {
            strings.push_back(word);
            counts.push_back(1);
        }
    }
    for (int i = 0; i != strings.size(); ++i) {
        cout << "The word " << strings[i] << " occurred " << counts[i] << " times." << endl;
    }
}
