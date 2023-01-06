#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include "Student_info.h"

// Copied from main.cpp from exercise 9.1
// This code solves 13-0 and ALSO 13-3.
// We plan to solve 13-4, 13-5, 13-6, 13-7, and 13-8 in this same solution.

// FIXME - getting error with reading some of the lines with the N > 2 case of student types
//         See console output!

using std::cin; using std::cout; using std::endl;
using std::string; using std::max; using std::vector;
using std::sort; using std::domain_error; using std::streamsize;
using std::setprecision;

/*
 * Ran into some fun pointer errors with the `read` function for
 * `Student_info`. Checking explicitly for EoF the character and
 * explicitly initializing `value` in Student_info to `nullptr`
 * made sure that:
 * 1. We did not continue to read lines past the EoF character,
 *    which was not an issue in other problems but was here.
 *    We're not sure why it was an issue this time.
 * 2. The delete statement in `read` didn't throw an error.
 *    We have to be extremely careful about:
 *    a) Using `delete` with a non-assigned pointer. Does not
 *       seem to work out very well. Need to explicitly assign
 *       to `nullptr`.
 *    b) Trying to delete a pointer twice by accident. We effectively
 *       did this in part of our code and the second `delete` call threw
 *       an error, saying the pointer had not been allocated.
 */
int main() {
    cout << "Please enter a list with each row being a student name, "
            "midterm grade, final grade, and one to many homework grades, "
            "all whitespace separated." << endl;

    Student_info record;
    vector<Student_info> records;
    string::size_type maxlen = 0; // Need to initialize value to make sure max operation behaves as expected!!!

    while(record.read(cin)) {
        records.push_back(record);
        maxlen = max(record.name().size(), maxlen);
    }

    sort(records.begin(), records.end(), compare); // Does alphabetical sort

    for(Student_info record: records){ // Using range-for instead of regular for loop. Achieves same invariant.
        cout << record.name() << string(maxlen + 1 - record.name().size(), ' ');

        if(record.valid()) {
            double final_grade = record.grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec); // Missing setprecision statements
            cout << " " << record.letter_grade();
        }
        else{
            cout << "INVALID";
        }

        cout << endl;
    }

    return 0;
}
