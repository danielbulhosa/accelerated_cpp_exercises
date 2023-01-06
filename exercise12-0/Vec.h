//
// Created by Daniel Bulhosa Solorzano on 1/27/21.
//

#ifndef EXERCISE11_0_VEC_H
#define EXERCISE11_0_VEC_H

#include <cstddef>
#include <memory>
#include <stdexcept>
#include <string>
#include <iostream>

/*
 * We misunderstood the book. We thought template methods
 * were allowed for template classes in the .cpp file. They're
 * not. Just like with template methods all (templated) members
 * of a template class must be defined in the header .h file.
 *
 */

template <class T>
class Vec {
public:
    typedef std::size_t size_type;
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;

    // Constructors
    Vec() {create();} // If empty make everything the null pointer
    Vec(size_type n, const T& val = T()) {create(n, val);}
    template <class It> Vec(It b, It e) {create(b, e);}
    // Exercise 12.13 - do a constructor (which defines a conversion and thus an assignment). Note we use 12.10 too!
    // Note we use a template for the size of the array! This is a great way of handling array decay for variable size array parameters!
    // See: https://stackoverflow.com/questions/3368883/how-does-this-size-of-array-template-function-work
    template <size_type size> Vec(T (&array)[size]) {create(array, array + size);};
    // Exercise 12.14 - we use the generalized `create` method that we implemented in 12.10
    Vec(std::string s) {create(s.begin(), s.end());};

    // Rule of three: the three functions below should always be defined together
    Vec(const Vec&); // copy constructor
    Vec& operator=(const Vec&); // assigment operator
    ~Vec(); // desctructor

    // Index Operator - Note it returns a reference to the element
    T& operator[](size_type n) {return data[n];}
    /* In this case we return a read only reference.
     * Second const promises method does not change object
     * members. Without second const the method would not
     * be callable from const instances of this class.
     */
    const T& operator[](size_type n) const {return data[n];}

    size_type size() const {return avail-data;}
    iterator begin() {return data;}
    const_iterator begin() const {return data;} // Need constant version for constant instances
    iterator end() {return avail;}
    const_iterator end() const {return avail;} // Need constant version for constant instances
    void push_back(T);
    void erase(iterator);
    void erase(iterator, iterator);
    void clear();
    template <class It> void insert(iterator, It, It); // Exercise 12.12

private:
    iterator data;
    iterator avail;
    iterator limit;
    std::allocator<T> alloc;
    void create();
    void create(size_type s, T val = T());
    // Exercise 12.10 - generalize create to take arbitrary iterators, not just `iterator` instances.
    template<class It> void create(It, It); // Nice -- we figured out what the book did here without looking! Just by debugging
    void uncreate();
    void grow();
    void unchecked_append(const T& val);
};

template <class T>
Vec<T>::Vec(const Vec& v){
/* Copy constructor: recall it takes a constant reference
 * to the object to be copied. It is a reference because
 * otherwise it would be a copy, but this IS the definition
 * of copy so that would be a contradiction. It is constant
 * because we don't want to modify the value we are copying.
 */
    create(v.begin(), v.end());
}

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& v){
/* Assignment operator: by convention the assigment operator
* always returns a reference to the left hand side! Assigment
* does not modify the value being copied into the existing
* object.
*/

    if(this != &v){ // Check for self reference
        // In general it makes sense to deallocate and reallocate since vectors may not have same size!
        uncreate(); // Deletes and deallocates memory
        create(v.begin(), v.end()); // Recreates somewhere new with values from vector being copied
    }

    return *this;
}

template <class T>
Vec<T>::~Vec(){
/* Desctructor: acts on object itself so it does not take any parameters.
* The destructor takes the tilda prefix in front of the constructor name
* to define.
*/
    uncreate();
}

template <class T>
void Vec<T>::push_back(T val){
    if (avail == limit){
        grow();
    }
    unchecked_append(val);
   ++avail;
}

// Exercise 12.12 -- appears template types cannot be declared together. They are declared hierarchically.
template <class T> template <class It>
void Vec<T>::insert(iterator position, It first, It last){
    /*
     * One approach would have been to copy the tail of vector
     * first and set `avail` = `position` then push back the
     * values to insert and the tail in that order.
     *
     * That approach is O(N) in memory because of that copy.
     * This approach shifts the values in the tail within the
     * same array which makes this O(1) in terms of memory.
     *
     * This approach loops through the input values twice, whereas
     * the other approach only would have once. If the number of input
     * values is larger and iterating through each is expensive the
     * other approach could have been preferable. In practice we
     * expect that not to be the case though for most reasonable
     * input value sequences.
     */

    size_type inputsize = 0;
    size_type vectorsize = this -> size();
    // We need the index because once we grow the vector the
    // pointer underlying `position` will become invalid.
    size_type index = position - data;

    for(It it = first; it != last; ++it) ++inputsize; // Calculate size of input sequence
    while(limit - data  < inputsize + vectorsize) grow(); // Grow until we can fit original vector and inputs

    // `grow` sets `avail` to (limit - data) / 2 because it assumes
    // grow only gets called by `push_back`. This is not the case so
    // we fix the value of `avail`. FIXME -- write different grow method for this?
    avail = data + vectorsize + inputsize;

    // Shift tail values first -- O(1) in memory
    for(size_type i = index; i != index + inputsize; ++i) (*this)[i + inputsize] = (*this)[i];
    size_type j = 0; // Now insert the values we originally wanted to insert
    for(It i = first; i != last; ++i) (*this)[index + (j++)] = *i;

}

template <class T>
void Vec<T>::create(){
    // Deferred constructor
    create(0);
}

template <class T>
void Vec<T>::create(const size_type size, const T val){
    // Note we already declared these members so we just assign now
    data = alloc.allocate(size);
    avail = limit = data + size;
    std::uninitialized_fill(data, avail, val);
}

// Exercise 12.10 - generalize create to take arbitrary iterators, not just `iterator` instances.
template <class T> template<class It>
void Vec<T>::create(It b, It e){
    // Note we use custom typedefs to abstract their implementation
    size_type size = 0;
    for(It iter = b; iter != e; ++iter) ++size;

    data = alloc.allocate(size);
    avail = limit = data + size;
    std::uninitialized_copy(b, e, data);
}

template <class T>
void Vec<T>::uncreate(){
    iterator b = begin(), e = end();
    for (iterator delptr = e; delptr != b; --delptr){ // This b != e is similar to condition data != 0 from book
        alloc.destroy(delptr);
    }
    size_type size = e-b;
    alloc.deallocate(b, size); // Deallocate memory reserved for underlying array
    avail = limit = data = 0; // Changed to match book
}

template <class T>
void Vec<T>::grow(){
    size_type size = limit - data;
    if (size == 0){
        data = alloc.allocate(1); // Allocate first element
        avail = limit = data + 1;
        return ;
    }

    iterator new_data = alloc.allocate(2 * size); // Create new array with twice the size
    std::uninitialized_copy(data, limit, new_data); // Copy existing data into new array
    uncreate();  // Get rid of the old array

    // Point data members to new underlying array
    data = new_data;
    avail = data + size;
    limit = data + 2*size;
}

template <class T>
void Vec<T>::unchecked_append(const T& val) {
    alloc.construct(avail, val);
}

template <class T>
void Vec<T>::erase(iterator b, iterator e){
    // Erases [b, e) -- note the open interval
    if(b < data || e > avail){
        throw std::domain_error("Iterators outside of valid range");
    }

    // Shift everything from after the range we want
    // to erase to the end of the available space to
    // the beginning of the space we want to erase.
    // We WILL have enough space allocated to write into
    // because by definition we are writing less data
    // than what we have available.
    std::copy(e, avail, b);
    avail = b + (avail - e);
};

template <class T>
void Vec<T>::erase(iterator it){
    erase(it, it + 1); // Just erase it
};

template <class T>
void Vec<T>::clear(){
    // Basically delete existing vector and then
    // create new empty one.
    uncreate();
    create();
};


#endif //EXERCISE11_0_VEC_H
