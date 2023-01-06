//
// Created by Daniel Bulhosa Solorzano on 1/13/21.
//

namespace algos {
    // All iterators should be input iterators.
    template<class It>
    bool equal(It b, It e, It b2) {
        while (b != e) {
            // Check values match and increment
            if (b++ != b2++) {
                return false;
            }
        }
        return true;

    }

    /* All iterators should be input iterators.
       Returns iterator at position where t is found. */
    template<class It>
    It find(It b, It e, typename It::value_type t) { // Note these are value params so copies are made
        while (b != e) {
            // Check reference equals value
            if (*b == t) {
                break;
            }
            ++b;
        }
        return b; // FIXME -- is it a problem this is a const_iterator? Probably, right?

    }

    /* Iterators b and e are input iterators. Iterator d is an output iterator.
       Returns initial value of d (seems reasonable?). */
    template<class It, class Out>
    Out copy(It b, It e, Out d) {
        Out o = d;
        while (b != e) {
            *(d++) = *(b++); // Assign input value to output value and increment iterators.
        }
        return o;
    }

    /* Iterators b and e are input iterators. Iterator d is an output iterator.
       p is a predicate from T -> bool.
       Returns initial value of d (seems reasonable?).
       FIXME - is functional parameter correct? */
    template<template<class> class C, class T>
    typename C<T>::iterator remove_copy_if(typename C<T>::const_iterator b,
                                           typename C<T>::const_iterator e,
                                           typename C<T>::iterator d,
                                           bool (p)(T)) {

        typename C<T>::iterator o = d;
        while (b != e) {
            if (!p(*b)) { // Check predicate for value, make sure it is false
                *(d++) = *(b++); // If so copy value into copy collection and increment.
            }
        }
        return o;

    }

    /* Iterators b and e are input iterators. Iterator d is an output iterator.
       f is a transformation from T -> T.
       Returns initial value of d (seems reasonable?).
       FIXME - is functional parameter correct? */
    template<template<class> class C, class T>
    typename C<T>::iterator transform(typename C<T>::const_iterator b,
                                      typename C<T>::const_iterator e,
                                      typename C<T>::iterator d,
                                      T (f)(T)) {
        typename C<T>::iterator o = d;
        while (b != e) {
            *(d++) = f(*(b++)); // Get value, transform with f, increment iterators.
        }
        return o;

    }

    /* All iterators should be input iterators.
       Returns sum of type T. */
    template<template<class> class C, class T>
    T accumulate(typename C<T>::const_iterator b,
                 typename C<T>::const_iterator e,
                 T t) {

        T ret;
        if (b != e) {
            ret = *(b++); // Assign first value and increment.
        }
        while (b != e) {
            ret += *(b++);
        }

        return ret;
    }

    /* All iterators should be input iterators.
       Returns iterator at position of where we
       first find sequence defined by b2, e2. */
    template<template<class> class C, class T>
    typename C<T>::iterator search(typename C<T>::const_iterator b,
                                   typename C<T>::const_iterator e,
                                   typename C<T>::const_iterator b2,
                                   typename C<T>::const_iterator e2) {
        while (b != e) {
            if (*b != *b2) { // If beginning values are not equal move up the beginning value on main collection.
                ++b;
            } else {
                typename C<T>::const_iterator i = b, i2 = b2;
                // If the first value b matches b2 then see if all values (b2, e2)
                // match with same number of values starting from b.
                while (i2 != e2) {
                    if (*(i++) != *(i2++)) { // Compare and increment.
                        break;
                    }
                }
                if (i2 == e2) { // If we found a match then i2 will have incremented enough times to be equal to e2.
                    return b; // FIXME -- is it a problem this is a const_iterator? Probably, right?
                } else { // Else just continue.
                    ++b;
                }
            }
        }

        return b; // If we get to this point then b == e; // FIXME -- is it a problem this is a const_iterator? Probably, right?

    }

    /* Iterators b and e are input iterators. p is a predicate from T -> bool.
       Returns iterator of first value returning true for the predicate.
       FIXME - is functional parameter correct? */
    template<template<class> class C, class T>
    typename C<T>::iterator find_if(typename C<T>::const_iterator b,
                                    typename C<T>::const_iterator e,
                                    bool (p)(T)) {
        while (b != e) {
            if (p(*b)) {
                return b;
            } else {
                b++;
            }
        }
        return b; // FIXME -- is it a problem this is a const_iterator? Probably, right?

    }

    /* Iterators b and e are input iterators. Iterator d is an output iterator.
       t is a value of type T.
       Returns initial value of d (seems reasonable?). */
    template<template<class> class C, class T>
    typename C<T>::iterator remove_copy(typename C<T>::const_iterator b,
                                        typename C<T>::const_iterator e,
                                        typename C<T>::iterator d,
                                        T t) {
        typename C<T>::iterator o = d;
        while (b != e) {
            if (*b != t) { // Check whether equal to t, make sure it is false
                *(d++) = *(b++); // If so copy value into copy collection and increment.
            }
        }
        return o;

    }

    /* Iterator b is a forward iterator. Iterator e is an input iterator
       t is a value of type T.
       Shuffles (b, e) so that values in front match t, return iterator
       points at first value past last that matched t. */
    template<template<class> class C, class T>
    typename C<T>::iterator remove(typename C<T>::iterator b,
                                   typename C<T>::const_iterator e,
                                   T t) {
        typename C<T>::iterator i = b; // Iterator i is used for writing to beginning of collection.
        while (b != e) {
            if (*b == t) {
                *(i++) = *b; // After last matching t i will be at position 1 + last match.
            }
            ++b;
        }
        return i;

    }

    /* Iterator b is a forward iterator. Iterator e is a reverse iterator. p is a predicate from T -> bool.
       Returns iterator of the first value for which the predicate is false.
       The function puts all values for which the sequence is true in front on sequence.
       FIXME - is functional parameter correct? */
    template<template<class> class C, class T>
    typename C<T>::iterator partition(typename C<T>::iterator b,
                                      typename C<T>::iterator e,
                                      bool (p)(T)) {
        /*
         * Note that our implementation does not preserve the order
         * of the elements on each side of the partition. For elements
         * meeting the predicate, those that were on the right side of
         * the partition will be in order, and elements that were on
         * the wrong side will be in reverse order! These two subsequences
         * will be interlaced so overall the full sequence will not have
         * any particular ordering.
         *
         * The same is true of elements not meeting the predicate, but on
         * the other side of the partition.
         */

        if (b != e) {
            --e; // Move e back initially so that *e is defined on first iteration.
        } else {
            return e; // Return e, because sequence is empty.
        }
        while (b != e) {
            // Find next e from end whose value meets predicate.
            // This is the next value than can be replaced.
            while (!p(*e) && b != e) {
                --e;
            }
            // Find next b from beginning whose value meets predicate.
            // This is the next value that can be replaced.
            while (p(*b) && b != e) {
                ++b;
            }
            if (b == e) {
                return ++e;
            }
                /* If we get to this point then b points to an element
                   that does not meet the predicate, e points to an
                   element that does, and b != e which means e is later
                   in the sequence than b so we should exchange these
                   values.

                    Next time we go through the loop since b now meets p
                    and e doesn't we will naturally move to the next iterator
                    values!
                */
            else {
                T b_val = *b, e_val = *e;
                *b = e_val;
                *e = b_val;
            }
        }
        return ++e; // We will only get here for sequences with one element, which skip the while loop altogether.
    }
}