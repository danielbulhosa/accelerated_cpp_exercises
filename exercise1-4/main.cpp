#include <iostream>
#include <string>

int main() {
    /* This program is valid because s is always defined within each scope.
     * However the s name from the higher scope gets overwritten by the s from
     * the lower scope. Hence the highlighting in the IDE.
     *
     * If we modify the program by moving the brackets it will still be valid
     * but the first s defined will be printed for the second statement because
     * the second s defined will get deleted once we get to the first `}`.
     *
     * Yup, that was it. NOICE.
     */

    {
        const std::string s = "a string";
        std::cout << s << std::endl;
    {
        const std::string s = "another string";}
        std::cout << s << std::endl;
    }//}
    return 0;
}
