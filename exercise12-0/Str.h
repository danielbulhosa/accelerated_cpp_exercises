//
// Created by Daniel Bulhosa Solorzano on 2/8/21.
//

#ifndef EXERCISE11_0_STR_H
#define EXERCISE11_0_STR_H

#include <cstring>
#include <iterator>
#include <iostream>
#include "Vec.h"

class Str {
public:
    typedef Vec<char>::size_type size_type;
    typedef Vec<char>::iterator iterator;
    typedef Vec<char>::const_iterator const_iterator;

    Str() {}; // Falls back on default Vec constructor, which creates empty Vec.
    Str(size_type n, char c): data(n, c) {}; // Falls on Vec constructor of same signature.
    // This constructor allows us to construct from null terminated character arrays.
    // Recall that since it takes a single parameter this one DEFINES A CONVERSION!
    // We have to use back inserter and copy because in Vec we ONLY defined the
    // Vec(It b, It e) constructor for Vec<T>::iterator = It.
    Str(const char* cp): data(cp, cp + std::strlen(cp)) {};
    // Exercise 12.10 - originally this constructor used std::copy because
    // the underlying constructor in Vec only took Vec<T>::iterator, but we
    // generalized that constructor to take templated iterators so now it works!
    template <class In> Str(In b, In e): data(b, e) {};

    size_type size() const {return data.size();};
    char& operator[](size_type n) {return data[n];};
    const char& operator[](const size_type n) const {return data[n];}; // Need a const version for read only Str.
    Str& operator+= (const Str& s) {std::copy(s.data.begin(), s.data.end(), std::back_inserter(this -> data));
                                    return *this;};
    // Make into friend because we use private member `data` of s
    friend std::istream& operator>>(std::istream& input, Str& s);

    // Exercise 12.2
    const char* c_str();
    const char* get_data(); // Named `get_data` instead of `data` since we already have data member `data`
    void copy(char*, int n) const;

    // Exercise 12.3
    friend bool operator>= (const Str&, const Str& );
    friend bool operator> (const Str&, const Str&);
    friend bool operator<= (const Str&, const Str&);
    friend bool operator< (const Str&, const Str&);

    // Exercise 12.4

    friend bool operator== (const Str&, const Str&);
    friend bool operator!= (const Str&, const Str&);

    // Exercise 12.6 -- if string is empty its underlying vector's size is zero!
    // Note that we need to make this explicit, otherwise all kinds of weird conversions happen!
    // C++ still performs 'contextual conversions' which suffice for our purposes. See:
    // https://stackoverflow.com/questions/39995573/when-can-i-use-explicit-operator-bool-without-a-cast
    explicit operator bool () const {return data.size() != 0;};

    // Exercise 12.7
    iterator begin() {return data.begin();};
    const_iterator begin() const {return data.begin();};
    iterator end() {return data.end();};
    const_iterator end() const {return data.end();};

    // Exercise 12.8
    friend std::istream& getline(std::istream& input, Str& s);

private:
    Vec<char> data;

    // Exercise 12.2
    char** cstr_ptr = nullptr; // Allocate empty to start for ease of use
    char** getdata_ptr = nullptr; // Allocate empty to start for ease of use
    static void update_pointer(char**& member_pointer, char*& new_pointer);
    char* create_array(bool null_terminate);

    // Exercise 12.8
    friend std::istream& input_until_predicate(std::istream& input, Str& s, bool pred(char));

};

// Make these methods non-members so that input and output objects
// can be left hand operands. Otherwise, if these were member methods
// then s would be implicit and would have to be on the left hand side.
// This disagrees with conventions around << and >> usage.
std::ostream& operator<<(std::ostream& output, const Str& s);
// We define this as a non-member so that this function is symmetric
// in the arguments. Otherwise the first argument would be implicit
// and would represent "this". This would limit our ability to convert
// the second argument.
Str operator+ (const Str& s1, const Str& s2);

// Exercise 12.4
int strcmp(Str&, Str&);


#endif //EXERCISE11_0_STR_H
