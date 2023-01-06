#include <iostream>

int main() {
    /*
     * We did this already in 9-0 and 9-1 so take a look at those.
     * The answer is to make the function static. This makes the
     * function part of the Student_info namespace but allows us
     * to use `homework` as a parameter without affecting the
     * data member `Student_info.homework`. Another alternative
     * would be to change the parameter `homework` to something like
     * `hw` but in that case it would still be clearer if we made
     * the method static for clarity.
     *
     * Recall that a member function of a class is static if it
     * does not reference the members of said class.
     */
}
