//
// Created by Daniel Bulhosa Solorzano on 2/21/21.
//

#include "Audit.h"
#include "Grad.h"
#include <istream>
#include <string>

using std::istream; using std::string;

istream& Audit::read(istream& input) {
    read_name(input);
    string s;
    getline(input, s);
    return input;
}

