#include <iostream>
#include "Vec.h"

int main() {
    Vec<int> v(10, 1);

    std::cout << "### TEST #1: Construct from size and val ###" << std::endl << std::endl;
    for(Vec<int>::iterator i = v.begin(); i != v.end(); ++i){
        std::cout << i << std::endl;
        std::cout << *i << std::endl;
    }

    Vec<int> v2;

    for(int i2 = 0; i2 != 10; ++i2){
        v2.push_back(i2);
    }

    std::cout << std::endl << "### TEST #2: Construct from default ###" << std::endl << std::endl;
    for(int i2 = 0; i2 != 10; ++i2){
        std::cout << v2[i2] << std::endl;
        std::cout << &v2[i2] << std::endl;
    }

    int array[10] = {9,8,7,6,5,4,3,2,1};
    Vec<int> v3(array, array + 10);

    std::cout << std::endl << "### TEST #3: Construct from array pointers ###" << std::endl << std::endl;
    for(int i3 = 0; i3 != 10; ++i3){
        std::cout << v3[i3] << std::endl;
        std::cout << &v3[i3] << std::endl;
    }

    v3 = v3;

    std::cout << std::endl << "### TEST #4: Self assign ###" << std::endl << std::endl;
    for(int i3 = 0; i3 != 10; ++i3){
        std::cout << v3[i3] << std::endl;
        std::cout << &v3[i3] << std::endl;
    }

    Vec<int> v4 = v3; // This is declaration of new variable, so it uses copy constructor
    std::cout << std::endl << "### TEST #5: Copy into other variable ###" << std::endl << std::endl;
    for(int i4 = 0; i4 != 10; ++i4){
        std::cout << v4[i4] << " " << v3[i4] << std::endl;
        std::cout << &v4[i4] << " " << &v3[i4] << std::endl;
    }

    Vec<int> v5(10, 1);
    v5 = v4; // This is assignment, so it uses assignment operator
    std::cout << std::endl << "### TEST #6: Assign into another variable ###" << std::endl << std::endl;
    for(int i5 = 0; i5 != 10; ++i5){
        std::cout << v5[i5] << " " << v4[i5] << std::endl;
        std::cout << &v5[i5] << " " << &v4[i5] << std::endl;
    }

    std::cout << std::endl << "### TEST #7: Destructor ###" << std::endl << std::endl;
    // Putting a print statement in the destructor shows it is called.
    // Running the code below shows that vdummy and vdummy2 keep changing
    // relative memory positioning. This suggests that we are in fact
    // destructing each variable -- as otherwise their memory locations
    // would persist! Looking at the pointer printouts confirms this!
    // The values get overwritten once they are destructed -- but remain
    // there unchanged before that.
    int* ptrarray[10];
    for(int i6 = 0; i6 != 10; ++i6){
        Vec<int> vdummy2;
        std::cout << std::endl << "Dummy 2" << std::endl;
        if(i6 != 0){
            vdummy2 =  Vec<int>(10, 1);
            for(int val: vdummy2){
                std::cout << " " << val;
            }
            std::cout << std::endl;
            std::cout << &vdummy2[0] << std::endl;

            std::cout << std::endl << "Pointer data 2" << std::endl;
            for(int* ptr: ptrarray){
                std::cout << " " << *ptr;
            }
            std::cout << std::endl;
            std::cout << ptrarray[0] << std::endl;
        }

        std::cout << std::endl << "Dummy 1" << std::endl;
        Vec<int> vdummy = v5;
        for(int val: vdummy){
            std::cout << " " << val;
        }
        std::cout << std::endl;
        std::cout << &vdummy[0] << std::endl;

        if(i6 == 0){
            for(int i7 = 0; i7 != 10; ++i7){
                ptrarray[i7] = &vdummy[i7];
            }
        }

        std::cout << std::endl << "Pointer data 1" << std::endl;
        for(int* ptr: ptrarray){
            std::cout << " " << *ptr;
        }
        std::cout << std::endl;
        std::cout << ptrarray[0] << std::endl;


    }

    // Out of scope variables have same or similar addresses
    // to in scope variables. This suggests that the memory
    // used by the in scope variables was in fact deleted!
    std::cout << std::endl << "Out of scope 1" << std::endl;
    Vec<int> v6 = v5;
    for(int val: v6){
        std::cout << " " << val;
    }
    std::cout << std::endl;
    std::cout << &v6[0] << std::endl;

    std::cout << std::endl << "Out of scope 2" << std::endl;
    Vec<int> v7 = v5;
    for(int val: v7){
        std::cout << " " << val;
    }
    std::cout << std::endl;
    std::cout << &v7[0] << std::endl;

    std::cout << std::endl << "### TEST #8: Empty Vec ###" << std::endl << std::endl;
    Vec<int> v8;
    std::cout << v8.begin() << " " << v8.end() << std::endl;

    std::cout << std::endl << "### TEST #9: Delete subset of elements + clear ###" << std::endl << std::endl;
    std::cout << std::endl << "### ORIGINAL ###" << std::endl << std::endl;
    Vec<int> v9 = v3;
    for(Vec<int>::iterator b = v9.begin(); b != v9.end(); ++b){
        std::cout << *b << std::endl;
        std::cout << b << std::endl;
    }

    std::cout << std::endl << "### DELETE SUBSET ###" << std::endl << std::endl;
    v9.erase(v9.begin() + 3, v9.begin() + 6);
    for(Vec<int>::iterator b = v9.begin(); b != v9.end(); ++b){
        std::cout << *b << std::endl;
        std::cout << b << std::endl;
    }

    std::cout << std::endl << "### CLEAR ALL ###" << std::endl << std::endl;
    v9.clear();
    for(Vec<int>::iterator b = v9.begin(); b != v9.end(); ++b){
        std::cout << *b << std::endl;
        std::cout << b << std::endl;
    }
    // Works since we expect there to be no elements
    // Note address changes though since we uncreate
    // and recreate the vector.
    std::cout << v9.begin() << " " << v9.end() << " " << v9.size();

    return 0;
}
