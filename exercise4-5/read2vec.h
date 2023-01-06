//
// Created by Daniel Bulhosa Solorzano on 1/6/21.
//

#ifndef EXERCISE4_5_READ2VEC_H
#define EXERCISE4_5_READ2VEC_H

#include <vector>
#include <iostream>
#include <string>

// We use references because the vectors get modified in place.
std::vector<std::string>& read(std::istream& input, std::vector<std::string>&);

#endif //EXERCISE4_5_READ2VEC_H
