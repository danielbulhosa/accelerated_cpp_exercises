#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include "student_info.h"
#include "grade.h"

using std::cin; using std::cout; using std::endl;
using std::string; using std::max; using std::vector;
using std::sort; using std::domain_error; using std::streamsize;
using std::setprecision;

int main() {
    // FIXME: Complete making the requested modifications. Skipping this problem because it's a bit repetitive.
    cout << "Please enter a list with each row being a student name, "
            "midterm grade, final grade, and one to many homework grades, "
            "all whitespace separated." << endl;

    Student_info record;
    vector<Student_info> records;
    string::size_type maxlen = 0; // Need to initialize value to make sure max operation behaves as expected!!!

    while(read(cin, record)) {
        records.push_back(record);
        maxlen = max(record.name.size(), maxlen);
    }

    sort(records.begin(), records.end(), compare); // Does alphabetical sort

    for(Student_info record: records){ // Using range-for instead of regular for loop. Achieves same invariant.
        cout << record.name << string(maxlen + 1 - record.name.size(), ' ');

        try {
            double final_grade = grade(record);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec); // Missing setprecision statements
        }
        catch (domain_error e) {
            cout << e.what();
        }

        cout << endl;
    }

    return 0;
}
