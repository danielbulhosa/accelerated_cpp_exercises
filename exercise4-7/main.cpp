#include <iostream>
#include <vector>
#include <iomanip>

using std::vector; using std::cout; using std::cin; using std::endl;
using std::setprecision; using std::streamsize;

int main() {

    cout << "Please enter a sequence of doubles separated by spaces: " << endl;

    vector<double> v;
    double x;

    while(cin >> x){
        v.push_back(x);
    }

    double sum = 0;
    double count = 1;

    if (v.empty()){
        cout << "The vector passed must not be empty." << endl;
        return 1;
    }

    for(double value: v){
        ++count;
        sum += value;
    }

    streamsize prec = cout.precision();
    cout << "The average of the numbers is: " << setprecision(3) << sum/count << endl;
}
