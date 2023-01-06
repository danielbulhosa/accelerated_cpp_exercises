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

stringsize width(const vector<string>& v){
    stringsize ret = 0; // We need to init to zero since we're taking max and we don't know what was previously stored there.
    vector<string>::const_iterator iter = v.begin();

    while(iter != v.end()){
        ret = max(iter -> size(), ret); // Recall -> means ( *). so we can use it to access member methods too!
        ++iter;
    }
    return ret;
}

vector<string> frame(const vector<string>& v){
    stringsize maxlen = width(v);
    vector<string> ret;
    // Two characters at each edge plus max text length.
    // REMEMBER: signature is (sizetype, char). NOT
    // (char, sizetype), (string, sizetype), or (sizetype, string).
    string top(2 + maxlen + 2, '*');

    transform(v.begin(),
              v.end(),
              back_inserter(ret),
              // Using a lambda here because otherwise it gets awkward to define a function whose
              // action depends on maxlen but only takes one parameter. For more info on lambdas see:
              // - https://stackoverflow.com/questions/7627098/what-is-a-lambda-expression-in-c11
              // - https://stackoverflow.com/questions/30217956/error-variable-cannot-be-implicitly-captured-because-no-default-capture-mode-h
              // Note that the initial brackets seem to allow passing context to the function...
              [&maxlen](const string& s){return "* " + s + string(maxlen - s.size(), ' ') + " *";});

    // This version of insert -- (iter, value) -- inserts the value at the position defined by iter!
    ret.insert(ret.begin(), top);
    ret.insert(ret.end(), top);

    return ret;

}