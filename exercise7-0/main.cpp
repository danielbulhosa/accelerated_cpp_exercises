#include <iostream>
#include <map>
#include <vector>
#include "xref.h"

using std::cout; using std::cin; using std::endl;
using std::map; using std::string; using std::vector;
using std::pair;

typedef map<string, vector<int> >::const_iterator mapiter;

int main() {
    cout << "Please enter several lines of words: " << endl;
    map<string, vector<int> > table = xref(cin, split);
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

    return 0;
}
