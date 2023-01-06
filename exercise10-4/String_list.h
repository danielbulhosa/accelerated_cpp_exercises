//
// Created by Daniel Bulhosa Solorzano on 1/24/21.
//

#ifndef EXERCISE10_4_STRING_LIST_H
#define EXERCISE10_4_STRING_LIST_H

#include <string>
#include <cstddef>
#include <algorithm>

class String_list {
public:
    String_list(std::size_t n): length(n), array(new std::string[n]) {};
    // This is called a delegated constructor: https://stackoverflow.com/questions/13961037/delegate-constructor-c
    String_list(): String_list(0) {};
    /*
     * The tricky thing here is that when arrays are passed to constructors
     * they "decay". What this means, is that what we get in the constructor
     * is not the array but instead a pointer to the array. The size of the
     * pointer to the array is not the same as the size of the array!
     * See: https://stackoverflow.com/questions/14308935/finding-the-size-of-an-string-array-in-c
     *
     * One trick with regular functions is passing the array as a reference
     * rather than as a value to the function. This solves the problem of
     * "array decay". See: https://www.geeksforgeeks.org/what-is-array-decay-in-c-how-can-it-be-prevented/
     *
     * However this trick only works when the function takes an array of
     * FIXED size. When the array's size is not declared this approach does
     * not work!
     *
     * Other solutions appear to be convoluted. Thus like the first Stack
     * Overflow article says a natural solution is just to pass the size
     * of the array to the constructor. Otherwise we would need to require
     * the definition of a special "null string" which does not exist.
     * We could have a null string if we worked with char[] string representations
     * instead of actual strings, but that we leave to another time.
     *
     * Note we need to initialize `array` before we copy into it. Otherwise we
     * do not have a valid pointer to use to write into the array!
     */
    String_list(std::string arr[], std::size_t n): length(n), array(new std::string[n]) {std::copy(arr, arr + n, array);};
    /* This is how we overload the indexing operator. Note that we return a
     * REFERENCE To the value we fetch so we can overwrite it! Otherwise (without
     * the `&` we would be returning a copy!!!
     */
    std::string& operator[] (int i) {return array[i];};

    class Iterator {
    public:
        Iterator(String_list slist, int n): pointer(slist.array + n) {};
        Iterator(std::string* p): pointer(p) {};
        /* Overload incrementers and decrementers: https://www.geeksforgeeks.org/increment-and-decrement-operator-overloading-in-c/
         * We return a new iterator with the correct value based on the increment operation.
         * This new iterator is a copy of the iterator on which we apply the operation. It is
         * NOT the same iterator.
         *
         * Overloading equality symbol: http://www.cplusplus.com/forum/beginner/125878/
         */
        Iterator operator++ () {return Iterator(++pointer);}; // Pre-increment
        Iterator operator++ (int) {return Iterator(pointer++);}; // Post-increment
        Iterator operator-- () {return Iterator(--pointer);}; // Pre-increment
        Iterator operator-- (int) {return Iterator(pointer--);}; // Post-increment
        // Iterators match (or not) if their underlying pointers match.
        bool operator== (Iterator other){return this->pointer == other.pointer;};
        bool operator!= (Iterator other){return this->pointer != other.pointer;};
        // Get the pointer in the iterator and dereference it. Note `this` is a
        // pointer to this object. Note implicitly this also leads to support for
        // assignment to deferenced value *var = val.
        std::string operator* () {return *(this->pointer);};
    private:
        std::string* pointer;
    };

    Iterator begin() {return Iterator(*this, 0);};
    Iterator end() {return Iterator(*this, length);};
    /*
     * A VERY inefficient implementation of push back for this
     * pseudo string-vector. The memory reallocation should be
     * done much less frequently than each time we cross the
     * threshold of the array. See:
     * https://stackoverflow.com/questions/1350630/how-to-expand-an-array-dynamically-in-c-like-in-vector
     */
    void push_back(std::string s) { std::string newarray[this->length + 1];
                                    std::copy(this->array, this->array + this->length, newarray);
                                    newarray[this->length] = s;
                                   *this = String_list(newarray, this->length + 1);}

private:
    std::size_t length;
    // We can't declare a variable length array. Apparently this is not allowed in C++11.
    // However we can declare a pointer to that array!
    std::string* array;
};

String_list split(std::string);

#endif //EXERCISE10_4_STRING_LIST_H
