//
// Created by Daniel Bulhosa Solorzano on 2/18/21.
//

#ifndef EXERCISE13_0_GRAD_H
#define EXERCISE13_0_GRAD_H

#include "Core.h"
#include <istream>
#include <string>

class Grad: public Core {
private:
    friend class Student_info; // Note friendship is not inherited so it must be declared in child classes again
protected:
    double thesis;
    // Return type needs to be Core* so that we override function with same return type
    // Note this is const because it doesn't modify the current object, just creates a copy elsewhere.
    Core* clone() const override {return new Grad(*this);};
public:
    Grad(): thesis(-1) {}; // Will call the constructor for Core before calling this constructor.
    Grad(std::istream& input): thesis(-1) {Grad::read(input);};

    // Need virtual destructor so that the correct destructor gets called polymorphically
    // We can use '= default' in C++11 to denote we want the default destructor.
    // See: https://en.cppreference.com/w/cpp/language/default_constructor
    // This is more explicit and obvious than just having empty brackets '{}'
    ~Grad() override = default;

    // We use override since C++11 (hence not in book)
    // See: https://en.cppreference.com/w/cpp/language/override
    // Without override the compiler throws an error for virtual functions!
    // This word seems to tell the compiler to override the base with this
    // function when dynamically binding! Note it goes before code block begins.
    std::istream& read(std::istream&) override;
    // We take the min of the core grade and the thesis grade
    double grade() const override {return std::min(Core::grade(), thesis);};
    std::string letter_grade() const override;

    bool valid() const override;
};


#endif //EXERCISE13_0_GRAD_H
