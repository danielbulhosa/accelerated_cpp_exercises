#include <iostream>

int main() {
    /*
     * We will not implement but because s would be outside of the scope of
     * the while loop it would not be reset at the beginning of each while.
     *
     * This means the string created at the end of each loop is the cumulative
     * string created from all previous iterations.
     *
     * Thus the image created would be:
     *
     * row1_1 row1_2
     * row1_1 row1_2row2_1 row2_2
     * row1_1 row1_2row2_1 row2_2row3_1 row3_2
     * .
     * .
     * .
     * row1_1 row1_2row2_1 row2_2row3_1 row3_2 ... row(n-1)_2row(n)_1 row(n)_2
     *
     * Note the lack of a space between the second row in the previous line and
     * the first row in the next line. This happens because at the beginning of
     * the next while loop we concatenate the next row without adding a space first!
     */
}
