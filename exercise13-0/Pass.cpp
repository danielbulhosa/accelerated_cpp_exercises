//
// Created by Daniel Bulhosa Solorzano on 2/21/21.
//

#include "Pass.h"

const std::vector<int> Pass::grade_thresholds = {60, 0};
const std::vector<std::string> Pass::grade_letters = {"P", "F"};

bool Pass::valid() const {
    return midterm >= 0 && final >= 0;
}

double Pass::grade() const {
    if (!homework.empty()){
        return Core::grade();
    }
    else {
        return (midterm + final)/2;
    }
}

std::string Pass::letter_grade() const {
    return lgrade(grade());
}