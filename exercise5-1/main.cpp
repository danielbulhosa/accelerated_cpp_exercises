#include <iostream>
#include <vector>
#include <string>
#include "permindex_struct.h"

using std::cin; using std::cout; using std::endl;
using std::vector; using std::string;

int main() {
    typedef string::size_type stringsize;

    cout << "Please enter a list of sentences, each separated by a new line: " << endl;

    vector<permindex_struct> sentences = index_from_input(cin);
    sort(sentences.begin(), sentences.end(), compare);
    stringsize max_prefix = max_prefix_length(sentences);

    for(const permindex_struct& pistruct: sentences){
        cout << string(max_prefix - pistruct.prefix.size(), ' ')
             << pistruct.prefix << string(5, ' ') << pistruct.index
             << endl;
    }

    return 0;
}
