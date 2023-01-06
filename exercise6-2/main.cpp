#include <iostream>
#include <string>
#include "findurl.h"

using std::string;
using std::cin; using std::cout; using std::endl;
using std::getline; using std::vector;

typedef std::string::const_iterator striter;

int main() {
    cout << "Please enter the text from which to parse URLs: " << endl;
    string line;
    string text;
    bool is_first = true;

    while(getline(cin, line)){
        if(!is_first){
            text += '\n';
        }
        else{
            is_first = false;
        }
        text += line;
    }

    vector<string> urls = find_urls(text);

    cout << "URLs found: " << endl;
    for(const string& url: urls){
        cout << url << endl;
    }
    return 0;

}
