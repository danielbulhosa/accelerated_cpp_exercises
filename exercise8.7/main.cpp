int main() {
    /*
     * `max` does not use a distinct template parameter for each
     * argument because max requires the < operator to be defined.
     * It is easier to support < being defined between members of a
     * single type. However, it is quite hard (and often impossible)
     * to define < between types, specially because all possible
     * combinations of types is likely combinatorically large. Hence
     * Defining max between different types is likely to return an
     * error more often than not, so it doesn't really make sense to
     * define it in this way as a general utility.
     */
}
