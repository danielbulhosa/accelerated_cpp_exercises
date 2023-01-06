#include <iostream>
#include "Li.h"

int main() {
    Li<int> v(10, 1);

    std::cout << "### TEST #1: Construct from size and val ###" << std::endl << std::endl;
    for(Li<int>::iterator i = v.begin(); i != v.end(); ++i){
        std::cout <<  i.get_pointer() -> previous << " " << i.get_pointer() << " " << i.get_pointer() -> next << std::endl;
        std::cout << *i << std::endl;
    }

    Li<int> v2;

    for(int i2 = 0; i2 != 10; ++i2){
        v2.push_back(i2);
    }

    std::cout << std::endl << "### TEST #2: Construct from default ###" << std::endl << std::endl;
    for(Li<int>::iterator i = v2.begin(); i != v2.end(); ++i){
        std::cout << *i << std::endl;
    }

    Li<int> v3(v2.begin(), v2.end());

    std::cout << std::endl << "### TEST #3: Construct from list pointers ###" << std::endl << std::endl;
    for(Li<int>::iterator i = v3.begin(); i != v3.end(); ++i){
        std::cout << *i << std::endl;
    }

    v3 = v3;

    std::cout << std::endl << "### TEST #4: Self assign ###" << std::endl << std::endl;
    for(Li<int>::iterator i = v3.begin(); i != v3.end(); ++i){
        std::cout << *i << std::endl;
    }

    Li<int> v4 = v3; // This is declaration of new variable, so it uses copy constructor
    std::cout << std::endl << "### TEST #5: Copy into other variable ###" << std::endl << std::endl;
    for(Li<int>::iterator i = v4.begin(); i != v4.end(); ++i){
        std::cout << *i << std::endl;
    }

    Li<int> v5(10, 1);
    v5 = v4; // This is assignment, so it uses assignment operator
    std::cout << std::endl << "### TEST #6: Assign into another variable ###" << std::endl << std::endl;
    for(Li<int>::iterator i = v5.begin(); i != v5.end(); ++i){
        std::cout << *i << std::endl;
    }

    std::cout << std::endl << "### TEST #7: Destructor ###" << std::endl << std::endl;
    // Putting a print statement in the destructor shows it is called.
    // Running the code below shows that vdummy and vdummy2 keep changing
    // relative memory positioning. This suggests that we are in fact
    // destructing each variable -- as otherwise their memory locations
    // would persist! Looking at the pointer printouts confirms this!
    // The values get overwritten once they are destructed -- but remain
    // there unchanged before that.
    Li<int>::Node* ptrarray[10];
    for(int i6 = 0; i6 != 10; ++i6){
        Li<int> vdummy2;
        std::cout << std::endl << "Dummy 2" << std::endl;
        if(i6 != 0){
            vdummy2 =  Li<int>(10, 1);
            for(Li<int>::iterator i = vdummy2.begin(); i != vdummy2.end(); ++i){
                std::cout << " " << *i;
            }
            std::cout << std::endl;
            std::cout << vdummy2.begin().get_pointer() << std::endl;

            std::cout << std::endl << "Pointer data 2" << std::endl;
            for(Li<int>::Node* ptr: ptrarray){
                std::cout << " " << ptr -> val;
            }
            std::cout << std::endl;
            std::cout << ptrarray[0] << std::endl;
        }

        std::cout << std::endl << "Dummy 1" << std::endl;
        Li<int> vdummy = v5;
        for(Li<int>::iterator i = vdummy.begin(); i != vdummy.end(); ++i){
            std::cout << " " << *i;
        }
        std::cout << std::endl;
        std::cout << vdummy.begin().get_pointer()  << std::endl;

        if(i6 == 0){
            int i7 = 0;
            for(Li<int>::iterator i = vdummy.begin(); i != vdummy.end(); ++i){
                ptrarray[i7] = i.get_pointer();
                ++i7;
            }
        }

        std::cout << std::endl << "Pointer data 1" << std::endl;
        for(Li<int>::Node* ptr: ptrarray){
            std::cout << " " << ptr -> val;
        }
        std::cout << std::endl;
        std::cout << ptrarray[0] << std::endl;


    }

    // Out of scope variables have same or similar addresses
    // to in scope variables. This suggests that the memory
    // used by the in scope variables was in fact deleted!
    std::cout << std::endl << "Out of scope 1" << std::endl;
    Li<int> v6 = v5;
    for(int val: v6){
        std::cout << " " << val;
    }
    std::cout << std::endl;
    std::cout << v6.begin().get_pointer() << std::endl;

    std::cout << std::endl << "Out of scope 2" << std::endl;
    Li<int> v7 = v5;
    for(int val: v7){
        std::cout << " " << val;
    }
    std::cout << std::endl;
    std::cout << v7.begin().get_pointer() << std::endl;

    std::cout << std::endl << "### TEST #8: Empty Li ###" << std::endl << std::endl;
    Li<int> v8;
    std::cout << v8.begin().get_pointer() << " " << v8.end().get_pointer() << std::endl;

    std::cout << std::endl << "### TEST #9: Delete subset of elements + clear ###" << std::endl << std::endl;
    std::cout << std::endl << "### ORIGINAL ###" << std::endl << std::endl;
    Li<int> v9 = v3;
    for(Li<int>::iterator b = v9.begin(); b != v9.end(); ++b){
        std::cout << *b << std::endl;
        std::cout << b.get_pointer() << std::endl;
    }

    std::cout << std::endl << "### DELETE SUBSET ###" << std::endl << std::endl;
    v9.erase((++(++(++v9.begin()))), (++(++(++(++(++(++v9.begin())))))));  // FIXME - should define iterator +/-
    for(Li<int>::iterator b = v9.begin(); b != v9.end(); ++b){
        std::cout << *b << std::endl;
        std::cout << b.get_pointer() << std::endl;
    }

    std::cout << std::endl << "### CLEAR ALL ###" << std::endl << std::endl;
    v9.clear();
    for(Li<int>::iterator b = v9.begin(); b != v9.end(); ++b){
        std::cout << *b << std::endl;
        std::cout << b.get_pointer() << std::endl;
    }
    // Works since we expect there to be no elements
    // Note address changes though since we uncreate
    // and recreate the vector.
    std::cout << v9.begin().get_pointer() << " " << v9.end().get_pointer() << " " << v9.size();

    std::cout << std::endl << "### TEST #10: Insert ###" << std::endl << std::endl;
    Li<int> v10 = v3;

    for(int i = 0; i != 5; ++i){
        v10.insert(1, (++(++(++v10.begin()))));
    }
    for(Li<int>::iterator b = v10.begin(); b != v10.end(); ++b){
        std::cout << *b << std::endl;
        std::cout << b.get_pointer() << std::endl;
    }


    return 0;
}
