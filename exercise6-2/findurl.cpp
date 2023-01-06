//
// Created by Daniel Bulhosa Solorzano on 1/10/21.
//

#include <vector>
#include <string>
#include <cctype>
#include "findurl.h"

using std::string; using std::vector; using std::isalnum;
using std::isalpha; using std::find_if;

typedef std::string::const_iterator striter;

bool not_url_char(const char& c){
    static const string valid_chars = "~;/?:@=&$-_.+!*'(),"; // Non-alphanumeric valid characters
    // c not found in valid_chars and is not alphanumerical
    return (find(valid_chars.begin(), valid_chars.end(), c) == valid_chars.end()) && !isalnum(c);
}

striter url_beginning (const striter& b, const striter& e){
    static string sep = "://";

    striter m = b;
    // Search for string sep in substring between m and e.
    // Note we assign to m before comparing to e and that m
    // starts equal to b.
    while((m = search(m, e, sep.begin(), sep.end())) != e){
        // Separator cannot be at beginning or end of string.
        // Note that IF sep is found at end of string then
        // m + sep.size() == e MUST be true since the size of
        // sep is fixed.
        if (m != b && m + sep.size() != e) {

            striter beg = m;
            // URL protocol should only include letters and cannot go
            // past beginning of string. Shift it back only as far as
            // we can meet these conditions.
            while (isalpha(beg[-1]) && beg != b) {
                --beg;
            }

            // m must have valid characters on either side of it.
            // We check first character is not in separator and that
            // at least firest char after separator is valid url char.
            if (beg != m && !not_url_char(m[sep.size()])) {
                return beg;
            }

            // Move next search start iter to end of last found separator.
            m += sep.size();
        }

    }

    return m; // NEED to return something. This way if we reach the end of the string the caller knows.
}

striter url_end (const striter& b, const striter& e){
    // Find first character that is not a URL character and return its iterator.
    return find_if(b, e, not_url_char);
}

vector<string> find_urls(string text){
    striter b = text.begin(), e = text.end();
    vector<string> urls;

    while(b != e){
        b = url_beginning(b, e);

        if (b != e){
            striter l = url_end(b, e);
            urls.push_back(string(b, l));
            b = l;
        }
    }

    return urls;
}