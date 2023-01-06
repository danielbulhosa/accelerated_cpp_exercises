//
// Created by Daniel Bulhosa Solorzano on 1/6/21.
//
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <stdexcept>
#include "student_info.h"
#include "grade.h"

using std::vector; using std::cin; using std::cout;
using std::endl; using std::istream; using std::domain_error;
using std::list;

bool compare(const Student_info& si1, const Student_info& si2){
    // Comparison needs to return whether first is less than second for it to work with sort method.
    return si1.name < si2.name;
}

istream& read_hw(istream& input, vector<double>& homework){
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

istream& read(istream& input, Student_info& student_info){
    // Note since this function has reference arguments the objects passed get changed in place.
    input >> student_info.name >> student_info.midterm >> student_info.final;
    read_hw(input, student_info.homework);
    return input;
}

// HIGHLIGHT: Added to create logic to extract students with failing grades.
//            Logic is written with generic container interface to make it portable
//            between vectors and lists.
Student_records extract_fail(Student_records& records) {
    Student_records failing_students;
    Student_records::iterator iter = records.begin();

    // Note we have to recalculate records.end() to update it when the iterator becomes invalid after deletions.
    // We need to use while loop instead of for because we don't always increment the iterator.
    while (iter != records.end()){
        Student_info record = *iter;
        bool student_failed;

        // In case we cannot calculate a homework grade. Then we can't say the student failed.
        try {
            student_failed = fgrade(record);
        }
        catch(domain_error){
            student_failed = false;
        }

        if (student_failed){
            // We erase the particular entry at the location the iterator points to.
            // Returned iterator points to correct next location.
            failing_students.push_back(record);
            iter = records.erase(iter);
        }
        else{
            // Move to next location otherwise.
            ++iter;
        }

    }

    return failing_students;
}
