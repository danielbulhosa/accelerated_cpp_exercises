//
// Created by Daniel Bulhosa Solorzano on 2/21/21.
//

#ifndef EXERCISE13_0_AUDIT_H
#define EXERCISE13_0_AUDIT_H

#include "Core.h"
#include <istream>
#include <string>

class Audit: public Core {
private:
    friend class Student_info;
protected:
    Core* clone() const override {return new Audit(*this);}; // Uses copy constructor
public:
    Audit() {}; // Will call the constructor for Core before calling this constructor.
    Audit(std::istream& input){Audit::read(input);};
    ~Audit() override = default;

    // We override this function so that it ignores whatever the input is.
    // We do this to be consistent with the `valid` function which doesn't
    // care what this class gets passed.
    std::istream& read(std::istream& input) override;

    // Students who audit do not get a grade.
    double grade() const override {return 0;};
    // Students who audit are always valid because grades don't matter!
    bool valid() const override {return true;};
    // Students who audit don't get a letter grade either
    std::string letter_grade() const override {return "N/A";};

};


#endif //EXERCISE13_0_AUDIT_H
