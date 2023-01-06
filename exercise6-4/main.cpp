#include <iostream>
#include<vector>
#include <algorithm>
using std::vector; using std::copy;
using std::cout; using std::cin; using std::endl;
using std::back_inserter;

int main() {
    vector<int> u(10, 100);
    cout << "The values in the vector `u` are: " << endl;
    for(int value: u){
        cout << value << endl;
    }
    cout << endl << "The number of values in `u` is: " << u.size() << endl;
    vector<int> v;

    // #1. The solution to the problem is to use an iterator adaptor
    // so we can dynamically add elements to the vector. The advantage
    // of this solution is that it works for any collection. Disadvantage
    // is syntax complexity and the fact that u values can't be modified
    // before putting into v.
    copy(u.begin(), u.end(), back_inserter(v));

    // #2. This is the another solution: to just use pushback.
    // Advantage is that it is very intuitive, would be easy to
    // add logic to change values before adding to v, and would work
    // with any container. Disadvantage is that it is relatively verbose.
    //for(int value: u) {
    //    v.push_back(value);
    //}

    // #3. Here is another solution, doing it in the constructor with iterators.
    // Advantage is that it is very succinct and that it would work for any
    // collection type. Disadvantage is that it is hard to add logic to modify
    // values of u before putting into v.
    //vector<int> v(u.begin(), u.end());

    cout << endl << "The values in the vector `v` are: " << endl;
    for(int value: v){
        cout << value << endl;
    }
}
