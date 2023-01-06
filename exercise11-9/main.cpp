int main() {
    /*
     * Let's assume we have a vector and that each time that we want
     * to append a new element we increase the size of the underlying
     * array. Let's assume that the initial size of the array is N and
     * that we append M times. The cost we pay at each append step is
     * the cost of copying the elements that were already in the vector.
     * This cost is always linear in the number of elements in the vector.
     *
     * If we add the costs for each addition from the 1st to the Mth we get
     * that the total cost is:
     *   O[ n + (n + 1) + ... (n + m - 1)] = O[(1/2) m x (m + 2n - 1)] = O[m^2 + m x n]
     *
     * In the simple case that we start with an empty vector (n=0) then this goes like
     * m squared. Clearly this is quite inefficient. Anything of cost quadratic or
     * larger is practically intractible.
     *
     * Instead, if each time that we run out of memory we increase it 2x this is
     * much more efficient. For ease, let's consider the n=0 case again. Let's look
     * at what happens after each new element is added:
     *
     * # Element Added      Memory Increase      Number of Copies
     *         1                0 -> 1                  0
     *         2                1 -> 2                  1
     *         3                2 -> 4                  2
     *         4                 NONE                   0
     *         5                4 -> 8                  4
     *         6                 NONE                   0
     *         7                 NONE                   0
     *         8                 NONE                   0
     *         9                8 -> 16                 8
     *        10                 NONE                   0
     *        11                 NONE                   0
     *        12                 NONE                   0
     *        13                 NONE                   0
     *        14                 NONE                   0
     *        15                 NONE                   0
     *        16                 NONE                   0
     *        17                16 -> 32               16
     *
     * In this case we pay the cost of copying exponentially less frequently!
     * If m is the total number of elements we add then we copy k - 1 elements
     * ONLY for every k <= m such that k - 1 is a power of 2 (e.g. 2^0, 2^1, ...).
     * So the total cost is:
     *
     *      O[ \sum_{k = 2}^{k <= m if k - 1 is power of 2} k ]
     *    = O[ \sum_{k - 1 = 1}^{k - 1 <= m if k - 1 is power of 2} k - 1 ] -- subtract 1 from all equalities
     *    = O[ \sum_{2^j = 1}^{2^j <= m} 2^j ]                              -- set k - 1 = 2j (e.g. power of 2)
     *    = O[ \sum_{j = 0}^{j <= log_2(m)} 2^j ]                           -- take log of both sides of inequality (log is monotonically increasing so this is valid)
     *    = O[ \sum_{j = 0}^{j = floor(log_2(m))} 2^j ]                     -- inequality saturated by floor since j is integral
     *    = O[ 2^{floor(log_2(m)) + 1}  - 1]                                -- Formula for series of 2^j
     *    = O[m]                                                            -- O(floor(x)) = O(x), cancel logs, ignore constant factors
     *
     * So increasing memory exponentially only exponentially frequently reduces
     * the cost of copying from O[m^2] to O[m]! By doing this we reduce the cost
     * of copying to a linear factor!
     *
     * We won't implement the comparison, we'll just leave this as a proof of
     * the asymptotic efficiency of this allocation strategy. We effective trade
     * compute (e.g. copying) for allocating more space ahead of time. For small
     * vectors this is a very reasonable trade-off.
     */
}
