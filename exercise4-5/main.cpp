#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "read2vec.h"
#include "wordstats.h"

using std::vector; using std::string;
using std::cin; using std::cout; using std::endl;
using std::sort; using std::length_error;

int main() {
    // Sort words after putting into vector. Will make complexity n x log(n) instead of n^2.

    cout << "Please enter a list of words separated by spaces: " << endl;
    vector<string> words;
    words = read(cin, words);
    sort(words.begin(), words.end());

    typedef vector<string>::size_type sizetype;
    sizetype num_words = number_of_words(words);
    vector<string> uniques = unique_words(words);
    vector<int> counts = counts_per_word(words);

    if (uniques.size() != counts.size()){
        throw length_error("Length of counts and unique word vectors should be the same.");
    }
    else{
        cout << "The number of words entered was: " << num_words << endl;

        for (int i = 0; i != uniques.size(); ++i){
            cout << "The word " << uniques[i] << " appeared "
                 << counts[i] << " times in the input word list."
                 << endl;
        }
    }
    return 0;

}
