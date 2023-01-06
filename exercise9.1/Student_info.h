//
// Created by Daniel Bulhosa Solorzano on 1/16/21.
//

#ifndef EXERCISE9_0_STUDENT_INFO_H
#define EXERCISE9_0_STUDENT_INFO_H

#include <vector>
#include <string>
#include <istream>
#include "median.h"

class Student_info {
private:
    std::string n;
    double midterm;
    double final;
    double final_grade;
    std::vector<double> homework;
    // HIGHLIGHT 9.1 - Define grade in the header.
    double calc_grade() const {return 0.4 * median(homework) + 0.2 * midterm + 0.4 * final;};
public:
    // Note the colon when defining the initialization of data members before constructor body!
    Student_info(): midterm(0), final(0) {}; // Default constructor. Uses vector and string default constructors.
    // Note constructor defined in header requires argument as well as signature to define body.
    Student_info(std::istream& input){read(input);}; // Constructor that reads from input IO stream.
    static std::istream& read_hw(std::istream&, std::vector<double>&);
    std::istream& read(std::istream&);
    // HIGHLIGHT 9.1 - Define getter for pre-computed grade.
    double grade() const {return final_grade;};
    bool valid() const;
    std::string name() const {return n;};
};

bool compare(const Student_info& record1, const Student_info& record2);

#endif //EXERCISE9_0_STUDENT_INFO_H
