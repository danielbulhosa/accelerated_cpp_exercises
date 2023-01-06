//
// Created by Daniel Bulhosa Solorzano on 1/24/21.
//

#include <string>
#include <algorithm>
#include <cctype>
#include "String_list.h"

typedef std::string::iterator striter;

String_list split(std::string s){
    String_list slist;
    striter b = s.begin();
    striter e = s.end();

    while(b != e){
        striter l = std::find_if(b, e, [](char c){return !std::isspace(c);});
        striter r = std::find_if(l, e, [](char c){return std::isspace(c);});
        std::string word = std::string(l,r);
        slist.push_back(word);
        b = r;
    }

    return slist;
}
