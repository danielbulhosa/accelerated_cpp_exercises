//
// Created by Daniel Bulhosa Solorzano on 1/12/21.
//

#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cctype>
#include "xref.h"

using std::string; using std::vector;
using std::istream; using std::map;
using std::getline; using std::search;
using std::isspace;

typedef string::const_iterator striter;
typedef string::size_type stringsize;
typedef map<string, vector<int> >::const_iterator mapiter;
typedef std::vector<std::string> (string_parser) (const std::string&);

vector<string> split(const string& s){
    vector<string> ret;
    striter b = s.begin(), e = s.end(), m;
    bool find_space = false;

    // Note we can't declare in the while loop, but we CAN ASSIGN!
    // Also note the use of a lambda with context passed. Finally,
    // assignment is right associative (I believe) and returns the
    // value assigned.
    while((m = find_if(b, e,[&find_space](const char& c){return find_space == isspace(c);})) != e){
        if (find_space){
            // If we find a space, we must have previously found a work.
            // Thus b = beginning of word and m = end of word.
            ret.emplace_back(b,m); // Emplace back calls the constructor of T for vector<T>. Here T = string.
        }
        b = m;
        find_space = !find_space;
    }

    // If we get here and we're looking for a space it means the
    // word in question is the last in the line.
    if(find_space){
        ret.emplace_back(b,m);
    }

    return ret;
}

// Function takes function as a parameter so we can change which kinds of words we look for.
map<string, vector<int> > xref(istream& input, string_parser& find_words){
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;

    while(getline(input, line)){
        ++line_number;
        vector<string> words = find_words(line);
        for(const string& word: words){
            ret[word].push_back(line_number);
        }
    }

    return ret;
}

// HIGHLIGHT - Added for exercise 7.1.
map<stringsize, vector<std::string> > count_occurrences (std::map<string, vector<int> >& word_lines){
    map<stringsize, vector<std::string> > ret;
    mapiter e = word_lines.end();

    for(mapiter b = word_lines.begin(); b != e; ++b){
        // b -> first is the word, (b -> second).size() is the number of occurrences of that word.
        ret[(b -> second).size()].push_back(b -> first);
    }

    return ret;
}