//
// Created by Daniel Bulhosa Solorzano on 1/10/21.
//

#ifndef EXERCISE6_2_FINDURL_H
#define EXERCISE6_2_FINDURL_H

#include <vector>
#include <string>

bool not_url_char(const char&);
std::string::const_iterator url_beginning (const std::string::const_iterator&,
                                           const std::string::const_iterator&);
std::string::const_iterator url_end (const std::string::const_iterator&,
                                     const std::string::const_iterator&);
std::vector<std::string> find_urls(std::string text);

#endif //EXERCISE6_2_FINDURL_H
