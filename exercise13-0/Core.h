//
// Created by Daniel Bulhosa Solorzano on 2/18/21.
//

#ifndef EXERCISE13_0_CORE_H
#define EXERCISE13_0_CORE_H

#include <vector>
#include <string>
#include <istream>
#include "median.h"


class Core {
public:
    // Copied from Student_info.h from exercise 9.1
    // Change constructors to make midterm and final -1.
    // Allows us to check that we read in enough values.
    // A better solution would determine validity on read and
    // store validity as a data member of the class.
    Core(): midterm(-1), final(-1) {};
    Core(std::istream& input): midterm(-1), final(-1) {Core::read(input);};
    virtual bool valid() const;
    std::string name() const {return n;};

    // We make these two functions virtual so that they can be
    // dynamically bound during run time and we have polymorphism!
    virtual std::istream& read(std::istream&);
    virtual double grade() const {return 0.4 * median(homework) + 0.2 * midterm + 0.4 * final;};

    // Need virtual destructor so that the correct destructor gets called polymorphically
    // We can use '= default' in C++11 to denote we want the default destructor.
    // See: https://en.cppreference.com/w/cpp/language/default_constructor
    // This is more explicit and obvious than just having empty brackets '{}'
    virtual ~Core() = default;

    static std::string lgrade(double);
    virtual std::string letter_grade() const;  // Added for Exercise 13-4

protected:
    // These are the members we need to be accessible by the child class
    static std::istream& read_hw(std::istream&, std::vector<double>&); // We use this method implement Grad::read
    std::istream& read_common(std::istream&); // We use this method implement Grad::read
    double midterm, final; // We use these members and `homework` to implement Grad::grade
    std::vector<double> homework;

    virtual Core* clone() const {return new Core(*this);}; // Use default copy constructor
    const static std::vector<int> grade_thresholds;
    const static std::vector<std::string> grade_letters;
    std::istream& read_name(std::istream&);

private:
    // Copied from Student_info.h from exercise 9.1
    std::string n;
    // Note that adding the keyword class allows us NOT to import
    // "Student_info.h and avoid a circular import. So when we declare
    // friend classes we need both keywords 'friend class'.
    friend class Student_info;
};


#endif //EXERCISE13_0_CORE_H
