int main() {
    /*
     * For the vector and string data members it
     * calls whatever the assignment operator defined
     * for these classes is. Those are probably similar
     * in spirit to what we implemented for the Vec class
     * in exercise 11-0.
     *
     * For the double data members our understanding from
     * section 11.3.5 is that the literal value in one memory
     * location is copied from one memory location to another.
     * This is not done in C++ but rather is done by the implementation
     * of the language itself (presumably in assembly code).
     * This should be generically true of built-in types.
     */
}
