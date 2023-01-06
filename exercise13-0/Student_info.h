//
// Created by Daniel Bulhosa Solorzano on 2/18/21.
//

#ifndef EXERCISE13_0_STUDENT_INFO_H
#define EXERCISE13_0_STUDENT_INFO_H

#include <string>
#include "Core.h"
#include <istream>

class Student_info {
public:
    Student_info(): value(nullptr) {};
    // We need to set `value` to `nullptr`. Otherwise when we try to delete it in `read` we get an error.
    // Only assigned pointers can be deleted. Declared but unassigned pointers cannot? Maybe it's a C++14 thing?
    Student_info(std::istream& input): value(nullptr) {read(input);};

    // Note copy constructor and assignment operator take references which make `value` into a reference
    // and hence make the methods polymorphic.
    Student_info(const Student_info& handle): value(handle.clone()) {}; // copy constructor
    Student_info& operator=(const Student_info&); // assignment operator
    // This delete call is polymorphic because we made the destructors virtual for Core and Grad
    ~Student_info() {delete value;}; // destructor

    std::string name() const {return value -> name();};  // Requests goes to dynamically bound class
    double grade() const {return value -> grade();};  // Requests goes to dynamically bound class
    bool valid() const {return value -> valid();}; // All requests go to Core, since valid is only defined there
    std::istream& read(std::istream&);
    std::string letter_grade() const {return value -> letter_grade();}; // Added for Exercise 13-4
private:
    Core* value;
    Core* clone() const {return value -> clone();};
};

// Copied from Student_info.h from exercise 9.1
// Note reference parameter will make these work with Grad objects!
bool compare(const Student_info& record1, const Student_info& record2);

#endif //EXERCISE13_0_STUDENT_INFO_H
