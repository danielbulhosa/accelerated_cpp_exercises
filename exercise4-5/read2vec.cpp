//
// Created by Daniel Bulhosa Solorzano on 1/6/21.
//

#include <vector>
#include <iostream>
#include <string>
#include "read2vec.h"

using std::vector; using std::istream; using std::cin; using std::string;

vector<std::string>& read(istream& input, vector<std::string>& v){
    string word;
    while(input >> word){
        v.push_back(word);
    }
    return v;
}