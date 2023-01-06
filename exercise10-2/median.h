//
// Created by Daniel Bulhosa Solorzano on 1/25/21.
//

#ifndef EXERCISE10_2_MEDIAN_H
#define EXERCISE10_2_MEDIAN_H

// Recall that templates must be defined in header file.
// Actual compiled code gets generated from template file
// into compiled code.

#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename Iterator>
/* See: https://stackoverflow.com/questions/44521991/type-trait-to-get-element-type-of-stdarray-or-c-style-array
 * and: https://stackoverflow.com/questions/20820520/how-to-get-dereferenced-type-of-template-member-for-function-return-type
 * Also note we pass vector/array by reference to avoid array decay.
 * This piece of code basically seems to:
 * - Declare a value of a template class
 * - Dereference the declared value
 * - Get the declared type for the dereferenced value
 * - Removed the reference from the declared type of the dereferenced value
 * We end up with the type of the elements of the container whose iterators
 * we're looking at.
 */
std::remove_reference_t<decltype(*std::declval<Iterator>())> // Real magic, need to understand these type computation methods...
median(Iterator b, Iterator e) {
    // Since we work with iterators or pointers we do arithmetic to figure out
    // the container size.
    int size = e - b;
    if(size == 0){
        throw std::domain_error("median of an empty vector");
    }
    // This type is whatever the type of the elements of the container is.
    // We create an array of that type.
    std::remove_reference_t<decltype(*std::declval<Iterator>())> copyarray[size];
    // We copy the elements of the container passed into an array, that we use
    // to find the median.
    std::copy(b, e, copyarray);
    // We sort the array rather than sorting the input container as to avoid
    // rearranging the input.
    std::sort(copyarray, copyarray + size);
    int mid = size/2;

    return size %  2 == 0 ? (copyarray[mid] + copyarray[mid - 1])/2 : copyarray[mid];
}

#endif //EXERCISE10_2_MEDIAN_H
