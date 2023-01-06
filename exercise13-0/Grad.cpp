//
// Created by Daniel Bulhosa Solorzano on 2/18/21.
//

#include "Grad.h"
#include <istream>

using std::istream;

istream& Grad::read(istream& input) {
    read_common(input);
    input >> thesis; // Add this line to read thesis grade!
    read_hw(input, homework);
    return input;
}

bool Grad::valid() const {
    return thesis >= 0 && Core::valid();
}

std::string Grad::letter_grade() const {
    return lgrade(grade());
}