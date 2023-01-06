//
// Created by Daniel Bulhosa Solorzano on 1/6/21.
//

#ifndef EXERCISE4_0_STUDENT_INFO_H
#define EXERCISE4_0_STUDENT_INFO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>

struct Student_info {
    std::string name;
    double midterm;
    double final;
    std::vector<double> homework;
};

// HIGHLIGHT: This typedef makes it seamless to go back and forth between vectors and lists.
typedef std::list<Student_info> Student_records;

bool compare(const Student_info& si1, const Student_info& si2);
std::istream& read_hw(std::istream& cin, std::vector<double>& homework);
std::istream& read(std::istream& cin, Student_info& student_info);
Student_records extract_fail(Student_records& records);

#endif //EXERCISE4_0_STUDENT_INFO_H
