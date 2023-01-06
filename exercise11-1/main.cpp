int main() {
    /*
     * We did not need to define the copy constructor,
     * assignment operator, or destructor for the
     * Student_info class. This is because this class
     * only has 4 data members: n, midterm, final, and
     * homework.
     *
     * n is a string and this standard library class
     * presumably has a reasonable copy constructor,
     * assignment operator, and destructor defined for it.
     * Same can be said for homework, which is of the vector
     * class. midterm and final are built-in types so
     * their copy constructors and assignments are trivial,
     * and their destructor is trivial as well (meaning it is
     * part of the core language itself).
     *
     * This being the case falling back on the default,
     * recursion based definitions for copy, assign, and
     * destruct for Student_info is reasonable. We know
     * that the implementations for each data member will
     * do the job reasonably.
     */
}
