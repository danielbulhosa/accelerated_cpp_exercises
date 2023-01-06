//
// Created by Daniel Bulhosa Solorzano on 1/8/21.
//

#ifndef EXERCISE5_1_PERMINDEX_STRUCT_H
#define EXERCISE5_1_PERMINDEX_STRUCT_H

#include <string>
#include <iostream>

struct permindex_struct {
    std::string index;
    std::string prefix;
};

std::string tolower(const std::string& s);

bool compare(const permindex_struct& pi1, const permindex_struct& pi2);

std::vector<permindex_struct> index_from_input(std::istream& input);

std::string::size_type max_index_length (const std::vector<permindex_struct>& v);

std::string::size_type max_prefix_length (const std::vector<permindex_struct>& v);

#endif //EXERCISE5_1_PERMINDEX_STRUCT_H
