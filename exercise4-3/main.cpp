#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
using std::cout; using std::cin;
using std::endl; using std::setw;
using std::string; using std::to_string;
using std::out_of_range;

int main() {
    int maxnum = 1000;
    int maxnumsq = maxnum * maxnum;

    // Padding is now amount of characters for longest square plus one for the space between them.
    unsigned long padding = to_string(maxnum).size() + 1 + to_string(maxnumsq).size();

    for(int i=1; i <= maxnum; ++i){
        int square = i*i;
        string::size_type size = to_string(i).size();

        // Correct for the growth of the number on the left column by `size`.
        // FIXME: Still a bit unclear still on how the padding is calculated and from where.
        if(size > padding){
            throw out_of_range("Cannot have `size > padding`.");
        }

        cout << i << setw(padding - size) << square << endl;
    }
}