//
// Created by Daniel Bulhosa Solorzano on 1/27/21.
//

#ifndef EXERCISE11_0_VEC_H
#define EXERCISE11_0_VEC_H

#include <cstddef>
#include <memory>

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
    typedef T value_type; // FIXME: Forgot from exercise!
    typedef T& reference;
    typedef const T& const_reference;

    // Constructors
    Vec() {create();} // If empty make everything the null pointer
    Vec(size_type n, const T& val = T()) {create(n, val);} // FIXME -- in book this was not a separate constructor. We made it into one.
    Vec(iterator b, iterator e) {create(b, e);}
    // Rule of three: the three functions below should always be defined together
    Vec(const Vec&); // copy constructor
    Vec& operator=(const Vec&); // assigment operator
    ~Vec(); // desctructor

    // Index Operator - Note it returns a reference to the element
    T& operator[](size_type n) {return data[n];} // FIXME - input type in book was size_type, not int
    /* In this case we return a read only reference.
     * Second const promises method does not change object
     * members. Without second const the method would not
     * be callable from const instances of this class.
     */
    const T& operator[](size_type n) const {return data[n];} // FIXME - input type in book was size_type, not int

    size_type size() {return avail-data;} // FIXME - Added, forgot this method
    iterator begin() {return data;}
    const_iterator begin() const {return data;} // Need constant version for constant instances
    iterator end() {return avail;}
    const_iterator end() const {return avail;} // Need constant version for constant instances
    void push_back(T);

private:
    iterator data;
    iterator avail;
    iterator limit;
    std::allocator<T> alloc;
    void create();
    void create(size_type s, T val = T());
    void create(const_iterator, const_iterator); // Nice -- we figured out what the book did here without looking! Just by debugging
    void uncreate();
    void grow();
    void unchecked_append(const T& val); // FIXME - in book this is const T&, not T
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
   ++avail; // FIXME -- book does this operation within unchecked append
}

template <class T>
void Vec<T>::create(){
    // Deferred constructor
    create(0); // FIXME - did this different from book. Tried book approach originally but led to bugs!
}

template <class T>
void Vec<T>::create(const size_type size, const T val){
    // Note we already declared these members so we just assign now
    data = alloc.allocate(size);
    avail = limit = data + size;
    std::uninitialized_fill(data, avail, val);
}

template <class T>
void Vec<T>::create(const_iterator b, const_iterator e){
    // Note we use custom typedefs to abstract their implementation
    size_type size = e - b;
    data = alloc.allocate(size);
    avail = limit = data + size;
    // FIXME -- book used shorthand. Return of this is `data + size`
    //          so we could have set `avail` and `limit` equal to this.
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
    // FIXME -  in book all pointers are set to zero and there is no `allocate`.
    //          Zero pointers seemed to create bugs for us though? Maybe check
    //          another time...
    alloc.allocate(data, 0); // For consistency with meaning of "empty" vector, `create(0)`
    avail = limit = data;
}

template <class T>
void Vec<T>::grow(){
    // FIXME - book did size == 0 a little cleaner
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


#endif //EXERCISE11_0_VEC_H
