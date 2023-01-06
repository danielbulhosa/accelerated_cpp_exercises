//
// Created by Daniel Bulhosa Solorzano on 1/6/21.
//

#ifndef EXERCISE4_0_GRADE_H
#define EXERCISE4_0_GRADE_H

#include <vector>

double grade(double midterm, double final, double hw);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(const Student_info& student_info);
bool fgrade(double grade);
bool fgrade(const Student_info& student_info);

#endif //EXERCISE4_0_GRADE_H
