//
// Created by Daniel Bulhosa Solorzano on 1/6/21.
//

#include <vector>
#include <string>
#include "wordstats.h"

using std::vector; using std::string;

vector<string>::size_type number_of_words(const vector<string>& v){
    return v.size();
}

vector<string> unique_words(const vector<string>& v){
    // Assumes the passed array is sorted.
    vector<string> unique;
    string current_word;

    for (const string word: v){ // Made const since word isn't modified after use.
        if (current_word.empty() || current_word != word){
            current_word = word;
            unique.push_back(word);
        }
    }

    return unique;
}

vector<int> counts_per_word(const vector<string>& v){
    // Assumes the passed array is sorted.
    vector<int> counts;

    string current_word;
    int count = 0;

    for (const string word: v){ // Made const since word isn't modified after use.
        if (current_word != word){
            if(!current_word.empty()){
                counts.push_back(count);
            }
            current_word = word;
            count = 1;
        }
        else {
            count += 1;
        }
    }

    counts.push_back(count);
    return counts;

}