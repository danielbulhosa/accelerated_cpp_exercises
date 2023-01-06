//
// Created by Daniel Bulhosa Solorzano on 1/12/21.
//

#ifndef EXERCISE7_0_XREF_H
#define EXERCISE7_0_XREF_H

#include <map>
#include <string>
#include <vector>
#include <iostream>

// Note how we use typedef here to declare a function signature.
// The form is ret_type (func_type_name) (arg_types)
typedef std::vector<std::string> (string_parser) (const std::string&);

std::vector<std::string> split(const std::string&);
// Note usage of custom type alias for function type. Also note that definition of
// default happens here in the declaration!!! (Maybe this is a C++14 thing?).
std::map<std::string, std::vector<int> > xref(std::istream&, string_parser& = split);

#endif //EXERCISE7_0_XREF_H
