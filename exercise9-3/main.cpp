int main() {
/*
 * Recall that when we declare an object of class
 * Student_info to be const this constrains the methods
 * that can be used with that particular instance. In particular,
 * we can only use const methods for the class in that particular
 * instance.
 *
 * In the case of our program the `compare` function takes two
 * `const` Student_info objects. If we name the member function
 * `name` nonconst then this method is unaccessible from `compare`
 * because compare can only access `const` member functions of
 * that object.
 */
}
