#include <iostream>
#include <map>
#include <vector>
#include "xref.h"

using std::cout; using std::cin; using std::endl;
using std::map; using std::string; using std::vector;
using std::pair;

typedef string::size_type stringsize;
typedef map<string, vector<int> >::const_iterator mapiter;
typedef map<stringsize, vector<std::string> >::const_iterator occuriter;

int main() {
    cout << "Please enter several lines of words: " << endl;
    // HIGHLIGHT: Replaced for exercise 7.3
    // map<string, vector<int> > table = xref(cin, split);
    map<string, vector<int> > table = xref(cin, split, true);
    map<stringsize, vector<std::string> > occurrences = count_occurrences(table);
    mapiter e = table.end();

    for(mapiter  b = table.begin(); b != e; ++b){
        bool is_first = true;
        pair<const string, vector<int> > word_entry = *b;
        cout << "The word **" << word_entry.first << "** occurred in lines: " << word_entry.second[0];

        for(const int word_line: word_entry.second){
            if(is_first){
                is_first = false;
                continue;
            }
            cout << ", " << word_line;
        }


        cout << endl;
    }

    cout << endl;

    // HIGHLIGHT - Added for exercise 7.1. Modified for exercise 7.3 for consistency.
    occuriter e2 = occurrences.end();
    for(occuriter  b2 = occurrences.begin(); b2 != e2; ++b2){
        bool is_first = true;
        pair<const stringsize, vector<string> > occur_entry = *b2;
        cout << "Words occuring in **" << occur_entry.first << "** lines (unique): " << occur_entry.second[0];

        for(const string& word: occur_entry.second){
            if(is_first){
                is_first = false;
                continue;
            }
            cout << ", " << word;
        }

        cout << endl;
    }

    return 0;

}
