int main() {
    /*
     * This problem is a proof not a program so we skip the code
     * and just write comments.
     *
     * The prompt is that given N values of a collection C of M
     * values where N < M and M is unknown, we want to prove
     * that we cannot calculate the median of C if we discard
     * any of the N values we already have.
     *
     * We could prove this formally but we are more focused on the
     * programming aspects of our learning. We lay the sketch of a proof
     * here and move on from this problem:
     *
     * Assume we have such a collection (c0, c1, ..., cN, ...cM). Suppose
     * we remove cn where n <= N and that when the sub-collection
     * (c0, c1, ..., cN) was sorted cn was the kth item in the sub-collection
     * where k <= N. For simplicity assume that M is odd, then we can always
     * choose M odd large enough and choose cN+1, ..., cM such that ck would have
     * been the median of the ful collection (c0, ..., cM). We have three cases:
     *
     * - If k < floor(N/2) then choose M = N + [floor(N/2) - k] and choose cN+1,
     *   ..., cM such that all of them are less than ck.
     * - If k > floor(N/2) then choose M = N + [k - floor(N/2)] and choose cN+1,
     *   ..., cM such that all of them are greater than ck.
     * - If k = floor(N/2) then choose M = 2 and choose cN+1 < ck and cN+2 > ck.
     *
     * In all three of these cases the result is that ck ends up being the median.
     * But since we removed it from the sequence it will not be found to be the median,
     * since we find the median by finding the center element of the sequence.
     *
     * A couple of gaps in our proof:
     * - Assuming M is odd.
     * - Assuming there isn't another cj with j <= N such that ck = cj.
     *
     * We believe both can be addressed but we will not attempt to do so.
     */
}
