//
// Created by Daniel Bulhosa Solorzano on 1/9/21.
//
#include <string>
#include <vector>
#include "ascenders.h"
using std::string; using std::vector;

const vector<char> descenders = {'q', 'y', 'p', 'g', 'j'};
const vector<char> ascenders = {'t', 'f', 'h', 'k', 'l', 'b', 'd'};

bool has_ascenders(const string& s){
    for(char c1: ascenders){
        for(char c2: s){
            if(c1 == c2){
                return true;
            }
        }
    }
    return false;
}

bool has_descenders(const string& s){
    for(char c1: descenders){
        for(char c2: s){
            if(c1 == c2){
                return true;
            }
        }
    }
    return false;
}

bool has_neither(const string& s){
    return !has_ascenders(s) && !has_descenders(s);
}