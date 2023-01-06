//
// Created by Daniel Bulhosa Solorzano on 1/6/21.
//

#ifndef EXERCISE4_5_WORDSTATS_H
#define EXERCISE4_5_WORDSTATS_H

#include <vector>
#include <string>

// We use const references because we do read only access to the references.
std::vector<std::string>::size_type number_of_words(const std::vector<std::string>&);
std::vector<std::string> unique_words(const std::vector<std::string>&);
std::vector<int> counts_per_word(const std::vector<std::string>&);

#endif //EXERCISE4_5_WORDSTATS_H
