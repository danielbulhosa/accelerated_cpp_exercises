int main() {
    /*
     * Because the + operator between those iterators is defined to
     * return an iterator. In mathematical notation:
     *
     *      +: iter x iter -----> iter
     *
     * On the other hand the - operator between those iterators is
     * defined to return an integer:
     *
     *      -: iter x iter -----> int
     *
     * The / operator is defined for two int arguments but it is NOT
     * defined for an iter argument and a int argument. Hence the operation
     * (begin + end) / 2 would have yielded a function not defined error.
     * (end - begin) / 2 does not throw and error and the subsequent operation
     * is + between an iter and an int which is defined,
     *
     *      +: iter x int -----> iter
     *
     * so we can do it without worrying about an error.
     */
}
