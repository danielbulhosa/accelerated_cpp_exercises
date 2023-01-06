//
// Created by Daniel Bulhosa Solorzano on 2/21/21.
//

#ifndef EXERCISE13_0_PASS_H
#define EXERCISE13_0_PASS_H

#include "Core.h"

class Pass: public Core {
private:
    friend class Student_info;
    const static std::vector<int> grade_thresholds;
    const static std::vector<std::string> grade_letters;
protected:
    Core* clone() const override {return new Pass(*this);}; // Uses copy constructor
public:
    Pass() {}; // Will call the constructor for Core before calling this constructor.
    Pass(std::istream& input){Core::read(input);}; // Shares read function with Core
    ~Pass() override = default;

    // Students who audit do not get a grade.
    double grade() const override;
    // Students who audit are always valid because grades don't matter!
    bool valid() const override;
    // Students who audit don't get a letter grade either
    std::string letter_grade() const override;
};


#endif //EXERCISE13_0_PASS_H
