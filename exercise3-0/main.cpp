// This is not exactly the program in the chapter because we attempted to recreate it from memory!
// We got it pretty close! Function is all there but print statements vary here and there.
#include <iostream>
#include <ios>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

using std::sort; using std::cin; using std::cout;
using std::endl; using std::vector; using std::string;
using std::setprecision; using std::streamsize;

int main() {
    cout << "Please enter your name: " << endl;
    string name;
    cin >> name;
    cout << endl << "Hi, " + name + "!" << endl; // Add initial endl to create more space.

    cout << "Please enter your midterm and final grades, in that order: " << endl;
    double midterm, final;
    cin >> midterm >> final;

    cout << endl << "Please enter all of your homework grades, followed by an End of File signal: " << endl;

    vector<double> hw_grades; // Note this declares a vector of doubles (extended floats)
    double hw_grade;

    // Invariant: we have added all input grades so far to the vector
    while (cin >> hw_grade) { // This condition evaluates to true while there is valid input
        hw_grades.push_back(hw_grade);
    }

    if (hw_grades.empty()) { // Checks if a vector is empty. Must be post C++98 since it does not appear in book.
        cout << endl << "You must enter at least one homework grade "
                        "to correctly calculate your grade average. "
                        "Please try again!" << endl;
        return 1; // Any non-zero code is a failure code.
    }

    typedef vector<double>::size_type vsize; // Need to use vector size type since it abstracts implementation details.

    sort(hw_grades.begin(), hw_grades.end()); // Not sure exactly how the sort function works... Sort happens in place.
    vsize mid = hw_grades.size()/2;
    double median = (hw_grades.size() % 2 == 0) ? (hw_grades[mid - 1] + hw_grades[mid])/2 : hw_grades[mid];
    double grade = 0.4 * final + 0.2 * midterm + 0.4 * median;

    streamsize prec = cout.precision(); // Get the current precision for print outs and save.
    cout << endl << "Your grade in the class is " << setprecision(3) << grade << endl; // Locally set new precision.
    cout.precision(prec);

    return 0;
}
