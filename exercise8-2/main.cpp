#include <iostream>
#include <string>
#include <vector>
#include "myalgorithms.h"

using std::cin; using std::cout; using std::endl;
using std::string; using std::vector; using std::back_inserter;

int main() {
    // Implement equal
    string s = "this is a test string";
    string m = "this is a test string as well";
    string n = "this is a different test string";
    cout << "for comparing `s` and `m`, `equal` returned: " << algos::equal(s.begin(), s.end(), m.begin()) << endl;
    cout << "for comparing `s` and `n`, `equal` returned: " << algos::equal(s.begin(), s.end(), n.begin()) << endl;

    // Implement find
    char yes_char = 'i'; // Should be found
    char no_char = 'f'; // Should not be found
    string::iterator iter1 = algos::find(s.begin(), s.end(), yes_char);
    cout << "first `i` found: " << *iter1 << " (position: " << (iter1 - s.begin()) << ")" << endl;
    iter1++;
    string::iterator iter2 = algos::find(s.begin() + (iter1 - s.begin()), s.end(), yes_char);
    cout << "second `i` found: " << *iter2<<  " (position: " << (iter2 - s.begin()) << ")" << endl;
    string::iterator iter3 = algos::find(s.begin(), s.end(), no_char);
    cout << "Was `f` found? (It shouldn't have been): " << !(iter3 == s.end()) << endl;

    // Implement copy
    string source = "this is a test";
    string target;
    algos::copy(source.begin(), source.end(), back_inserter(target));
    cout << "The original string was: `" << source << "` The copied string is: `" << target << "`" << endl;

    // Implement remove_copy_if
    string target2;
    algos::remove_copy_if(source.begin(), source.end(), back_inserter(target2), [](char c){return c == 't';});
    cout << "The characters extracted were: " << target2 << endl;

    // Implement transform
    string target3;
    algos::transform(source.begin(), source.end(), back_inserter(target3),
                     [](char c){return (c == 't') ? '1' : '0';});
    cout << "The characters transformed were: " << target3 << endl;

    // Implement accumulate
    vector<double> vec = {1.2, 2.3, 3.5, 4.0};
    double sum = algos::accumulate(vec.begin(), vec.end(), 4.2);
    cout << "The sum was (should be 15.2): " << sum << endl;

    // Implement search
    string search_target = "is a"; // FIXME -- some error here... It extracts "is i" rather than is "is a"...
    string::iterator  iter4 = algos::search(source.begin(), source.end(), search_target.begin(), search_target.end());
    cout << "The substring extracted was: ";
    for(string::size_type i = 0; i != search_target.size(); ++i){
        cout << *(iter4 + i);
    }
    cout << endl;

    // Implement find_if
    string::iterator iter5 = algos::find_if(source.begin(), source.end(), [](char c){return (c == 'a');});
    cout << "The character found was: " << *iter5 << " (position: " << (iter5 - source.begin()) << ")" << endl;

    // Implement remove_copy
    string target4;
    algos::remove_copy(source.begin(), source.end(), back_inserter(target4), 't');
    cout << "The characters extracted were: " << target4 << endl;

    // Implement remove
    string source_copy = source;
    string::iterator iter6 = algos::remove(source_copy.begin(), source_copy.end(), 't');
    cout << "The full final removed string is: " << source_copy << endl;
    cout << "The characters on and after the remove pointer are: ";
    for(string::iterator iter = iter6; iter != source_copy.end(); ++iter){
        cout << *iter;
    }
    cout << endl;

    // Implement partition
    string source_copy2 = source;
    string::iterator iter7 = algos::partition(source_copy2.begin(), source_copy2.end(), [](char c){return (c == 't');});
    cout << "The final partitioned string is: " << source_copy2 << endl;
    cout << "The characters on and after the partition start pointer are: ";
    for(string::iterator iter = iter7; iter != source_copy2.end(); ++iter){
        cout << *iter;
    }
    cout << endl;

    return 0;
}
