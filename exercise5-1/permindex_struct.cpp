//
// Created by Daniel Bulhosa Solorzano on 1/8/21.
//

#include "permindex_struct.h"
#include "stringsplit.h"
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using std::vector; using std::istream; using std::string;
using std::getline; using std::max; using std::tolower;

typedef string::size_type stringsize;

string tolower(const string& s){
    string ret;
    for(char c: s){
        ret += tolower(c);
    }
    return ret;
}

bool compare(const permindex_struct& pi1, const permindex_struct& pi2){
    string index1 = tolower(pi1.index);
    string index2 = tolower(pi2.index);

    return index1 < index2;
}

vector<permindex_struct> index_from_input(istream& input){
    vector<string> split_sentence;
    string sentence;
    vector<permindex_struct> ret;

    while(getline(input, sentence)) {
        split_sentence = split(sentence);
        for(stringsize i = 0; i != split_sentence.size(); ++i){
            permindex_struct permindex;
            for(stringsize j = 0; j != i; ++j){
                if (j != 0){
                    permindex.prefix += " ";
                }

                permindex.prefix += split_sentence[j];
            }

            for(stringsize j = i; j != split_sentence.size(); ++j){
                if (j != i){
                    permindex.index += " ";
                }
                permindex.index += split_sentence[j];
            }
            ret.push_back(permindex);
        }
    }
    return ret;
}

stringsize max_index_length (const vector<permindex_struct>& v){
    stringsize maximum = 0;
    for(const permindex_struct& element: v){
        maximum = max(maximum, element.index.size());
    }
    return maximum;
}

stringsize max_prefix_length (const vector<permindex_struct>& v){
    stringsize maximum = 0;
    for(const permindex_struct& element: v){
        maximum = max(maximum, element.prefix.size());
    }
    return maximum;
}