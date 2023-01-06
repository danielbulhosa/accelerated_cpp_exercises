#include <iostream>

// This will not work because you cannot have nested /* */ symbols.
// C++ does not escape these nested symbols and thus assumes the comment
// ends earlier than intended. Note though that not having * symbols at
// the beginning of each comment line does not have an effect though.

int main() {
    /* This is a comment that extends over several lines
       because it uses /* and */ as its starting and ending delimiters */
    std::cout << "Does this work?" << std::endl;
    return 0;
}
