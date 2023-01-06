//
// Created by Daniel Bulhosa Solorzano on 1/10/21.
//

#include <vector>
#include <string>
#include <algorithm>
#include "frame.h"

using std::vector; using std::string; using std::max;
using std::back_inserter; using std::transform;

typedef vector<string>::size_type stringsize;

vector<string> hcat(const vector<string>& v1, const vector<string>& v2){
    vector<string> ret;
    stringsize padto = width(v1) + 1;
    vector<string>::const_iterator iter1 = v1.begin(), iter2 = v2.begin();

    while(iter1 != v1.end() || iter2 != v2.end()){ // Stop when we've reached the end of both
        string s;
        if(iter1 != v1.end()){
            s = *iter1 + string(padto - (iter1 -> size()), ' ');
            ++iter1;
        }
        else{
            s = string(padto, ' ');
        }
        if(iter2 != v2.end()){
            // Note we could have incremented iter2++ in the same line.
            // We don't because we cannot safely do this with iter1 since it
            // appears twice in its expression.
            s += *iter2;
            ++iter2;
        }
        ret.push_back(s);
    }

    return ret;

}