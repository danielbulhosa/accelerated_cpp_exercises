//
// Created by Daniel Bulhosa Solorzano on 2/18/21.
//

#include "Core.h"
#include <istream>
#include <string>
#include <vector>

// Copied from Student_info.cpp from exercise 9.1
using std::vector; using std::string; using std::istream;

// Static data members cannot be assigned inline, they must be assigned in the implementation file.
// The only exception is for C++17 and later where we can use the keyword `inline`.
// Added for Exercise 13-4
const std::vector<int> Core::grade_thresholds = {97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0};
const std::vector<std::string> Core::grade_letters = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"};

istream& Core::read_hw(istream& input, vector<double>& homework){
    // Helper static method. Variable homework here is NOT the member variable homework!
    if(input){
        homework.clear();
        double grade;
        while(input >> grade){
            homework.push_back(grade);
        }
        input.clear();
    }
    return input;
}

istream& Core::read_name(istream& input){
    input >> n;
    return input;
}

istream& Core::read_common(istream& input) {
    read_name(input);
    input >> midterm >> final;
    return input;
}

istream& Core::read(istream& input) {
    read_common(input);
    read_hw(input, homework);
    return input;
}

bool Core::valid() const {
    return midterm >= 0 && final >= 0 && !homework.empty();
}

std::string Core::lgrade(double g) {
    for(int i = 0; i != grade_thresholds.size(); ++i){
        if(g >= grade_thresholds[i]){
            return grade_letters[i];
        }
    }
    throw std::runtime_error("The grade calculated did not match any letter grades.");

}

// Added for Exercise 13-4. We added it to the Student_info
// class rather than Core & Grad so we can use it polymorphically.
std::string Core::letter_grade() const {
    return lgrade(grade());
}