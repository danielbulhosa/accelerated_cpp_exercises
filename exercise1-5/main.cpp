#include <iostream>
#include <string>

int main() {
    /* The program is not valid because x is used outside of the
     * scope in which it is defined.
     *
     * We can fix it by putting the declaration of x in the same
     * scope as the print statement for x.
     */

    {
        std::string s = "a string";
    {   std::string x = s + ", really";
        std::cout << s << std::endl;//}
        std::cout << x << std::endl;}
    }
    return 0;


}
