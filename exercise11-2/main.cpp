int main() {
    /*
     * The Student_info defined a default constructor
     * because the default initialization for the midterm
     * and final members would lead to errors.
     *
     * The default initialization for these data members
     * just keeps whatever junk was saved in the register
     * we use to store the value of the data members before
     * we declared it. This value could be anything consistent
     * with the type double, which could lead to significantly
     * skewed grade results. In general this is the case for
     * built-in types -- they will default initialize to whatever
     * junk was in the register!
     */
}
