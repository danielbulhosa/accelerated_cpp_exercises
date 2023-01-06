#include <iostream>
#include <algorithm>
#include "String_list.h"

using std::string; using std::cout; using std::endl;

int main() {
    string arr[] = {"hello", "there", "I", "am", "Daniel", "WOAH"};
    String_list slist(arr, 5);
    slist[4] = "Mariah";

    for(String_list::Iterator i = slist.begin(); i != slist.end(); ++i){
        cout << *i << endl;
    }

    string longstring = "hey there my name is daniel hello!   there!";
    String_list slist2 = split(longstring);

    for(String_list::Iterator i = slist2.begin(); i != slist2.end(); ++i){
        cout << *i << endl;
    }
}
