#include <iostream>

int main() {
    /* The program is invalid because `+` is left associative and the sum of the
     * first two operands (two string literals) is invalid! The sum operation is
     * not defined for string literals (which are char arrays).
     *
     * However if we associate the terms of the right explicitly then the expression
     * works because then we have a char[N] + string sum.
     */

    const std::string exclam = "!";
    // const std::string message = "Hello" + ",world" + exclam; // Does not work
    const std::string message = "Hello" + (",world" + exclam);

    return 0;
}

