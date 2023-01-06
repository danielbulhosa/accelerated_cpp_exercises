#include <iostream>

int main() {
    /* The program is valid because `+` is left associative and the sum of the
     * first two operands (a string and a string literal) return a string, for
     * which the second sum is valid and defined.
     *
     * Furthermore none of the constant names are reassigned so the `const`
     * constraint is not violated.
     */

    const std::string hello = "Hello";
    const std::string message = hello + ",world" + "!";

    return 0;
}
