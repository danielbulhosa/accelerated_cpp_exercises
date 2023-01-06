//
// Created by Daniel Bulhosa Solorzano on 1/8/21.
//

#include <vector>
#include <string>
#include <cctype>
#include "stringsplit.h"

using std::vector; using std::string;
using std::isspace;

vector<string> split(const string& s) {
    typedef string::size_type stringsize;
    stringsize size = s.size(), i = 0;
    vector<string> ret;

    while(i != size) {
        while(i != size && isspace(s[i])){
            ++i;
        }

        stringsize j = i;
        while(j != size && !isspace(s[j])) {
            ++j;
        }

        if (i != j){
            ret.push_back(s.substr(i, j-i));
            i = j;
        }
    }

    return ret;
}
