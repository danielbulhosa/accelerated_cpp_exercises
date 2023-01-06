//
// Created by Daniel Bulhosa Solorzano on 1/16/21.
//

#ifndef EXERCISE9_0_STUDENT_INFO_H
#define EXERCISE9_0_STUDENT_INFO_H

#include <vector>
#include <string>
#include <istream>

class Student_info {
private:
    std::string n;
    double midterm;
    double final;
    std::vector<double> homework;
public:
    // Note the colon when defining the initialization of data members before constructor body!
    Student_info(): midterm(0), final(0) {}; // Default constructor. Uses vector and string default constructors.
    // Note constructor defined in header requires argument as well as signature to define body.
    Student_info(std::istream& input){read(input);}; // Constructor that reads from input IO stream.
    static std::istream& read_hw(std::istream&, std::vector<double>&);
    std::istream& read(std::istream&);
    double grade() const;
    bool valid() const;
    std::string name() const {return n;};
};

bool compare(const Student_info& record1, const Student_info& record2);

#endif //EXERCISE9_0_STUDENT_INFO_H
