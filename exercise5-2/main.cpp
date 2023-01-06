#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include "student_info.h"
#include "grade.h"

using std::cin; using std::cout; using std::endl;
using std::string; using std::max; using std::vector;
using std::domain_error; using std::streamsize;
using std::setprecision; using std::sort;

int main() {
    cout << "Please enter a list with each row being a student name, "
            "midterm grade, final grade, and one to many homework grades, "
            "all whitespace separated." << endl;

    Student_info record;
    Student_records records;
    string::size_type maxlen = 0; // Need to initialize value to make sure max operation behaves as expected!!!

    while(read(cin, record)) {
        records.push_back(record);
        maxlen = max(record.name.size(), maxlen);
    }

    // HIGHLIGHT: Here we add the logic for removing students with failing grades.
    //            Note this method modifies its parameter.
    Student_records fail = extract_fail(records);
    // sort(records.begin(), records.end(), compare); // HIGHLIGHT: Can't use sort. Not shared interface between list and vector...

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
