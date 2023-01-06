//
// Created by Daniel Bulhosa Solorzano on 1/9/21.
//

#include <vector>
#include <string>
#include <algorithm>
#include "center.h"

using std::vector; using std::string; using std::max;

vector<string> center(const vector<string>& rows){
    string::size_type maxlen = 0;

    for(const string& row: rows){
        maxlen = max(maxlen, row.size());
    }

    vector<string> ret;
    for(const string& row: rows){
        string::size_type padding = maxlen - row.size();
        string::size_type left_padding = (padding % 2 == 0) ? padding / 2 : padding / 2 + 1;
        string::size_type right_padding = padding / 2;

        ret.push_back(string(left_padding, ' ') + row + string(right_padding, ' '));
    }

    return ret;
}