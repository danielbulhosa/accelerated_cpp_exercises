//
// Created by Daniel Bulhosa Solorzano on 1/6/21.
//
#include <string>
#include <vector>
#include <iostream>
#include "student_info.h"

using std::vector; using std::cin; using std::cout; using std::endl;

bool compare(const Student_info& si1, const Student_info& si2){
    // Comparison needs to return whether first is less than second for it to work with sort method.
    return si1.name < si2.name;
}

std::istream& read_hw(std::istream& input, std::vector<double>& homework){
    if(input){
        homework.clear(); // This is how it was done in the example though we think this function should not handle this.
        double grade;
        while(input >> grade){
            homework.push_back(grade);
        }
        input.clear(); // To clear the state of the input after failure so we can use it later.
    }
    return input;
}

std::istream& read(std::istream& input, Student_info& student_info){
    // Note since this function has reference arguments the objects passed get changed in place.
    input >> student_info.name >> student_info.midterm >> student_info.final;
    read_hw(input, student_info.homework);
    return input;
}
