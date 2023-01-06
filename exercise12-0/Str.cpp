//
// Created by Daniel Bulhosa Solorzano on 2/8/21.
//

#include "Str.h"
#include <iostream>
#include <cctype>
#include <stdexcept>
#include <cstring>

using std::istream; using std::ostream; using std::cout;

// Note we make parameters const to make explicit
// that the arguments are not changed by the method.
Str operator+ (const Str& s1, const Str& s2){
    // Use += definition to define +
    Str out = s1;
    out += s2;
    return out;
};

// This method is a friend so that we can use the underlying
// methods of the vector class that stores the string chars.
// We generalized this from `operator>>` so we could reuse the
// same logic for `getline`.
std::istream& input_until_predicate(std::istream& input, Str& s, bool pred(char)){

    s.data.clear(); // HIGHTLIGHT! Had forgotten to clear underlying vector before passing input!
    char c;
    // Iterate through input until we either end input
    // or find a character meeting the predicate.
    while(input.get(c) && pred(c));

    // Only start getting more characters if we didn't
    // reach end of file. Otherwise we may go past end of file?
    if(input) {
        // Iterate through input until we either end input
        // or find a character meeting predicate. We do first before
        // checking while because first c failing condition
        // above must be not meet the predicate!
        do{s.data.push_back(c);}
        while (input.get(c) && !pred(c));

        // If input was not end of file (which means bool input
        // is true) then unget the character meeting the predicate
        // we must have gotten by accident.
        if (input) {
            input.unget();
        }
    }
    return input;

}

// Exercise 12.0, but refactored for 12.8
istream& operator>>(istream& input, Str& s){
    // isspace returns non-zero is true, we do comparison in lambda to cast to correct return type for predicate
    return input_until_predicate(input, s, [](char c){return isspace(c) != 0;});
}

// Exercise 12.8 -- implement near >> since they are similar!
std::istream& getline(std::istream& input, Str& s){
    return input_until_predicate(input, s, [](char c){return c == '\n';});
}

// Note we pass and return by reference since we
// want the same output object in and out!
ostream& operator<<(ostream& out, const Str& s){
    for(Str::size_type i = 0; i != s.size(); ++i){
        out << s[i];
    }
    return out;
}


char* Str::create_array(bool null_terminate){
    size_type size = this -> size();
    char* array = new char[size + null_terminate];

    for(size_type i = 0; i != size; ++i){
        array[i] = (*this)[i];
    }
    if(null_terminate){
        array[size] = '\0';
    }
    return array;
}

// Note `static` is only stated in the class method declaration
void Str::update_pointer(char**& member_pointer, char*& new_pointer){
    if (member_pointer != nullptr) {  // Only null when we've never called this method before
        delete *member_pointer; // Delete the previous array
    }
    member_pointer = &new_pointer; // Save pointer to pointer pointing to new array (so we can delete later)
}

// Exercise 12.2 -- did not specify when update needs to happen.
// for c_str and get_data. So we update any time the methods are called!
const char* Str::c_str(){
    char* array = create_array(true);
    update_pointer(cstr_ptr, array);
    return array;
}

const char* Str::get_data(){
    char* array = create_array(false);
    update_pointer(getdata_ptr, array);
    return array;

}

// Note to make method itself constant we put const after the method name
void Str::copy(char* p, int n) const {
    size_type num = n;
    if(num > this -> size()){
        throw std::invalid_argument("n must be smaller than the size of the string");
    }

    for(size_type i = 0; i != n; ++i){
        p[i] = (*this)[i];
    }
}

int strcmp(const Str& s1, const Str& s2){
    // We want strcmp to take const arguments, so we have to
    // use Str::copy instead of Str::c_str because the latter
    // modifies one of the data members of Str (cstr_ptr).
    // That member is needed to manager the char* created by c_str.

    char chars1[s1.size() + 1]; char chars2[s2.size() + 1];
    s1.copy(chars1, s1.size()); s2.copy(chars2, s2.size());
    chars1[s1.size()] = '\0'; chars2[s2.size()] = '\0';

    return std::strcmp(chars1, chars2);
}

// Exercise 12.3 -- define externally so we can have symmetric conversions!
// Make arguments const since these methods should work even for const Str.
bool operator>= (const Str& s1, const Str& s2){
    return strcmp(s1, s2) >= 0;
}

bool operator> (const Str& s1, const Str& s2){
    return strcmp(s1, s2) > 0;
}

bool operator<= (const Str& s1, const Str& s2){
    return strcmp(s1, s2) <= 0;

}

bool operator< (const Str& s1, const Str& s2){
    // strcmp is negative when first argument is less than second
    return strcmp(s1, s2) < 0;
}

// Exercise 12.4 -- define externally so we can have symmetric conversions!
bool operator== (const Str& s1, const Str& s2){
    return strcmp(s1, s2) == 0;
}

bool operator!= (const Str& s1, const Str& s2){
    return strcmp(s1, s2) != 0;
}
