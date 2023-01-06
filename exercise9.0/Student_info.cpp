//
// Created by Daniel Bulhosa Solorzano on 1/16/21.
//

#include <istream>
#include <string>
#include <vector>
#include "median.h"
#include "Student_info.h"

using std::vector; using std::string; using std::istream;

// Helper static method. Variable homework here is NOT the member variable homework!
istream& Student_info::read_hw(istream& input, vector<double>& homework){
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

istream& Student_info::read(istream& input) {
    // Note since this function has reference arguments the objects passed get changed in place.
    input >> n >> midterm >> final;
    read_hw(input, homework);
    return input;
}

double Student_info::grade() const {
    return 0.4 * median(homework) + 0.2 * midterm + 0.4 * final;
}

/*
 * Note that unlike in Python we do not require a keyword like
 * `self` to let Python know that a variable is a member of an
 * object. In fact, it's the opposite, if we want C++ to know it's
 * NOT a member of the object we would have to use ::homework to
 * state that the `homework` variable we seek does not belong to a
 * scope
 */
bool Student_info::valid() const {
    return !homework.empty();
}

bool compare(const Student_info& si1, const Student_info& si2) {
    // Comparison needs to return whether first is less than second for it to work with sort method.
    return si1.name() < si2.name();
}