#include <iostream>
#include <list>
#include "Vec.h"
#include "Str.h"

using std::cout; using std::cin; using std::endl;

int main() {
    // ### EXERCISE 12.0 TESTS ###
    // Conversions work! Very cool!
    Str s1 = "Hello there, "; // Literal should be of type char*, hence converted.
    char arr[18] = {'m', 'y', ' ', 'n', 'a', 'm', 'e', ' ', 'i', 's', ' ', 'D', 'a', 'n', 'i', 'e', 'l', '\0'}; // Note null termination needed!!!
    Str s2 = arr; // arr should be of type char*, hence the conversion works.
    Str s3(arr); // Here we use the constructor explicitly.

    cout << s1 << endl; // Write single string.
    cout << s1 + s2 << endl; // Write string plus string sum.
    cout << s1 + "nice to meet you!" << endl; // Sum conversion, one orientation
    cout << "Ahoy, maties! " + s3 << endl;  // Sum conversion, opposite orientation

    Str greeting = s1;

    cout << "Please enter a greeting: " << endl;
    cin >> greeting;
    greeting += " " +  s3; // Test sum-assignment
    cout << greeting << endl;

    // ### EXERCISE 12.2 TEST: Str to char array creation ###

    const char* cstr_array = s2.c_str();
    const char* getdata_array = s2.get_data();

    for(Str::size_type idx = 0; idx != s2.size(); ++idx){
        cout << s2[idx] << " " << cstr_array[idx] << " " << getdata_array[idx] << endl;
    }

    if(cstr_array[s2.size()] == '\0'){
        cout << "Pass null termination condition!" << endl;
    }

    if(getdata_array[s2.size()] != '\0'){
        cout << "Optional: getdata result is null terminated (not required to be)" << endl;
    }

    char strcopy[s2.size() + 1];
    s2.copy(strcopy, s2.size());

    for(char* ptr = strcopy; *ptr != '\0'; ++ptr){
        cout << *ptr;
    }
    cout << endl;


    // ### EXERCISE 12.3 TEST ###
    cout << "\n### EXERCISE 12.3 TEST: Relation Operators ###\n" << endl;

    Str comp1 = "Hello there";
    Str comp2 = "Hello here";
    char comp3[] = {'H', 'e', 'l', 'l', 'o', ' ', 't', 'h', 'e', 'r', 'e', '\0'};

    cout << "Expecting `False`: " << (comp1 < comp1) << endl; // False, trivial
    cout << "Expecting `False`: " << (comp1 < comp2) << endl; // False, comp2 comes first
    cout << "Expecting `False`: " << (comp1 < comp3) << endl; // False, trivial assuming conversion

    cout << "Expecting `False`: " << (comp1 > comp1) << endl; // False, trivial
    cout << "Expecting `True`: " << (comp1 > comp2) << endl; // True, comp2 comes first
    cout << "Expecting `False`: " << (comp1 > comp3) << endl; // False, trivial assuming conversion

    cout << "Expecting `True`: " << (comp1 <= comp1) << endl; // True, trivial
    cout << "Expecting `True`: " << (comp2 <= comp1) << endl; // True, comp2 comes first
    cout << "Expecting `True`: " << (comp3 <= comp1) << endl; // True, trivial assuming conversion

    cout << "Expecting `True`: " << (comp1 >= comp1) << endl; // True, trivial
    cout << "Expecting `False`: " << (comp2 >= comp1) << endl; // False, comp2 comes first
    cout << "Expecting `True`: " << (comp3 >= comp1) << endl; // True, trivial assuming conversion

    // ### EXERCISE 12.4 TEST ###
    cout << "\n### EXERCISE 12.4 TEST: Equality Operators ###\n" << endl;

    cout << "Expecting `True`: " << (comp1 == comp1) << endl; // True, trivial
    cout << "Expecting `False`: " << (comp1 == comp2) << endl; // False, is different
    cout << "Expecting `True`: " << (comp1 == comp3) << endl; // True, trivial assuming conversion

    cout << "Expecting `True`: " << (comp1 == comp1) << endl; // True, trivial
    cout << "Expecting `False`: " << (comp1 == comp2) << endl; // False, is different
    cout << "Expecting `True`: " << (comp1 == comp3) << endl; // True, trivial assuming conversion

    // ### EXERCISE 12.6 TEST ###
    cout << "\n### EXERCISE 12.6 TEST: Str Boolean Conversion ###\n" << endl;

    Str sfalse = "";
    Str strue = "some text!";

    if(sfalse){
        cout << "TEST FAILED!" << endl;
    }
    if(strue){
        cout << "TEST SUCCEEDED!" << endl;
    }

    // ### EXERCISE 12.7 TEST ###
    cout << "\n### EXERCISE 12.7 TEST: Str Class Iterators ###\n" << endl;
    for(Str::iterator iter = s2.begin(); iter != s2.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;

    // ### EXERCISE 12.8 TEST ###
    cout << "\n### EXERCISE 12.8 TEST: Str getline Method ###\n" << endl;
    cout << "Please enter a greeting with multiple words: " << endl;
    getline(cin, greeting);
    greeting += " " +  s3;
    cout << greeting << endl;


    // ### EXERCISE 12.10 TEST ###
    cout << "\n### EXERCISE 12.10 TEST: Construct Vector Arbitrary Iterators ###\n" << endl;
    std::list<int> mylist = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Vec<int> intvec1(mylist.begin(), mylist.end());

    for(Vec<int>::iterator iter = intvec1.begin(); iter != intvec1.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;

    // ### EXERCISE 12.12 TEST ###
    cout << "\n### EXERCISE 12.12 TEST: Insert Into Vector ###\n" << endl;
    // FIXME - When constructing vector(10, 0) the template constructor gets called instead of the
    //         constant value constructor. How can we fix this for constant integer vectors?
    Vec<char> insertvec(4, 'o');
    char insertarray[5] = {'a', 'b', 'c', 'd', 'e'};
    Vec<char>::iterator insertiter = insertvec.begin();
    ++(++insertiter); // Increment twice

    insertvec.insert(insertiter, insertarray, insertarray + 5);

    for(Vec<char>::iterator iter = insertvec.begin(); iter != insertvec.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;


    // ### EXERCISE 12.13 TEST ###
    cout << "\n### EXERCISE 12.13 TEST: Construct Vector From Array ###\n" << endl;
    int intarray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Vec<int> intvec2(intarray);

    for(Vec<int>::iterator iter = intvec2.begin(); iter != intvec2.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;

    // ### EXERCISE 12.14 TEST ###
    cout << "\n### EXERCISE 12.14 TEST: Construct Vector From String ###\n" << endl;
    std::string mystring = "this is a test";
    Vec<char> stringvec(mystring);

    for(Vec<char>::iterator iter = stringvec.begin(); iter != stringvec.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;



    return 0;
}
