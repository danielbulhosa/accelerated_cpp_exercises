#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
using std::cout; using std::cin;
using std::endl; using std::setw;
using std::string; using std::to_string;
using std::out_of_range; using std::setprecision;
using std::streamsize;

int main() {
    double maxnum = 1000;
    double maxnumsq = maxnum * maxnum;

    // Padding is now amount of characters for longest square plus one for the space between them.
    unsigned long padding = to_string(maxnum).size() + 1 + to_string(maxnumsq).size();

    streamsize prec = cout.precision();
    for(double i=1.0; i <= maxnum; ++i){
        double square = i*i;
        string::size_type size = to_string(i).size();
        string::size_type sizesq = to_string(square).size();

        // Correct for the growth of the number on the left column by `size`.
        // FIXME: Still a bit unclear still on how the padding is calculated and from where.
        //        It is specially weird that the alignment depends on the type. Doubles get more
        //        padding?
        if(size > padding){
            throw out_of_range("Cannot have `size > padding`.");
        }

        // Precision is exactly the number of digits in the number.
        cout << setprecision(size) <<  i << setw(padding - size) << setprecision(sizesq) << square << endl;
    }
    cout.precision(prec);
}