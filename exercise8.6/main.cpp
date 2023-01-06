#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using std::vector; using std::map; using std::string; using std::pair; using std::copy; using std::back_inserter;

int main() {
    /*
     * In each case x must be of type V<pair<const int, string>>,
     * where V is some container type. Iterating through m yields pairs
     * which would need to be written into a container that takes pairs.
     * In the second case we need to insert pair<const int, string> instances
     * from x into m which means that x must be again of the stated type.
     *
     * Let's test it, using vector as our container.
     */

    vector<pair<const int, string> > x;
    // Note map literals is just a bracketed list of bracketed tuples
    map<int, string> m = {{1, "hello"}, {2, "there"}, {3, "friend"}};
    copy(m.begin(), m.end(), back_inserter(x));

    vector<pair<const int, string> > x2 = {{1, "hello"}, {2, "there"}, {3, "friend"}};
    // Note map literals is just a bracketed list of bracketed tuples
    map<int, string> m2;
    // Copy does not work for m since m does not have a `push_back` method.
    //copy(x2.begin(), x2.end(), back_inserter(m2));
    // We need to use the `insert` method of the map type.
    // Our type reasoning about x holds though.
    m2.insert(x2.begin(), x2.end());

    return 0;
}
