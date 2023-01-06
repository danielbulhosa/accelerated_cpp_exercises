//
// Created by Daniel Bulhosa Solorzano on 1/6/21.
//
#include <stdexcept>
#include "student_info.h"
#include "median.h"
#include "grade.h"

using std::vector; using std::domain_error;

double grade(double midterm, double final, double hw){
    return 0.4 * hw + 0.2 * midterm + 0.4 * final;
}

double grade(double midterm, double final, const vector<double>& hw){

    if (hw.empty()){
        throw domain_error("Student has done no homework");
    }
    else {
        return grade(midterm, final, median(hw));
    }
}

double grade(const Student_info& student_info){
    return grade(student_info.midterm, student_info.final, student_info.homework);
}