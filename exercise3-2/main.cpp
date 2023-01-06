#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using std::vector; using std::cout;
using std::cin; using std::endl;
using std::sort; using std::max;

int main() {
    // Number of quantiles we want. 4 gives us quartiles. 10 would give us deciles.
    double quantiles = 4;

    cout << "Enter a list of numbers: " << endl;
    vector<double> v;
    double val;

    // Take in a list of values for which to get the quantiles
    while(cin >> val) {
        v.push_back(val);
    }

    if (v.empty()) {
        cout << "You must enter at least one value, please try again!";
        return 1;
    }

    double size = v.size(); // Using double so we can divide by it successfully.
    sort(v.begin(), v.end());
    vector<double> quantile_values; // The current quantile we are trying to find.

    /*
     * Basic idea is to go through all of the sorted values in the passed sequence
     * and find the first value outside of a given quantile. We then take the previous
     * value in the sequence as the quantile value for the previous quantile.
     */

    for(int quantile = 1; quantile <= quantiles; ++quantile) {
        // FIXME: Fails when size < quantiles, seems to be a shift error. Averaging not accounted for though.
        int index = max(floor(size * quantile/quantiles), 1.0) - 1; // We need to shift since vector is zero indexed
        cout << index << endl;
        quantile_values.push_back(v[index]);
    }

    cout << "These are the quantile values: " << endl;
    for (double value: quantile_values){
        cout << value << ", ";
    }
    return 0;
}
