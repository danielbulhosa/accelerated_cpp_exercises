//
// Created by Daniel Bulhosa Solorzano on 2/18/21.
//

#include "Student_info.h"
#include "Core.h"
#include "Grad.h"
#include "Audit.h"
#include "Pass.h"
#include <string>
#include <vector>
#include <istream>
#include <stdexcept>

std::istream& Student_info::read(std::istream& input){
    // Check for EoF, see: https://stackoverflow.com/questions/34274593/how-to-check-cin-is-end-of-file
    if (input.peek() != std::char_traits<char>::eof()){
        delete value; // HIGHLIGHT - Forgot to add this deletion to overwrite value already in place.

        char student_type;
        input >> student_type;

        // Use initial input code to initialize correct class
        if (student_type == 'U') {
            value = new Core(input);
        } else if (student_type == 'G') {
            value = new Grad(input);
        } else if (student_type == 'A') {
            value = new Audit(input);
        } else if (student_type == 'P') {
            value = new Pass(input);
        } else {
            throw std::invalid_argument(
                    "Input must start with a correct student type code. Got '" + std::string(1, student_type) + "' instead.");
        }
    }
    else {
        input.setstate(std::ios_base::failbit);
    }

    return input;
}

// Note assignment operator takes a reference which makes value a reference and hence we can use it polymorphically
Student_info& Student_info::operator= (const Student_info& handle) { // assignment operator
    if(this != &handle){
        delete value;
        if(handle.value) { // HIGHLIGHT: Check non-null -- forgot this from book! Otherwise method call would fail.
            value = handle.clone(); // Only one data member to update!
        }
        else{
            value = nullptr;
        }
    }

    return *this;
}

bool compare(const Student_info& si1, const Student_info& si2) {
    return si1.name() < si2.name();
}
