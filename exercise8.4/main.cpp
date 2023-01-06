int main() {
    /*
     * You need to use a swap operation because you need to have a
     * copy of at least one of the values being swapped. Otherwise
     * one of them will have to be overwritten and will be lost.
     * Below is an example.
     */

    int x = 1;
    int y = 2;
    int store;

    store = x;
    x = y;
    y = store;

    /* In a real swap function store would be within the scope of the
     * function and x and y would be separate reference parameters of
     * the function. Then we only occupy the memory in `store` until
     * the swap operation is done.
     */
}
