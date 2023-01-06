//
// Created by Daniel Bulhosa Solorzano on 1/9/21.
//

#include <string>
#include "palindrome.h"
using std::string;

bool is_palindrome(const string& s){
    string::size_type i = 0, j = s.size() - 1;

    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        ++i;
        --j;
    }
    return true;
}