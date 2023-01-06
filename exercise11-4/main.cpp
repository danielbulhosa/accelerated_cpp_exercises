#include <iostream>

int main() {
    /*
     * It probably only truly destroys and
     * deallocates the string and vector members.
     * Built-in types are not destroyed. Their values
     * are left in the register to be overwritten by
     * the next declared variable that uses that memory
     * location. See section 11.3.5.
     */
}
