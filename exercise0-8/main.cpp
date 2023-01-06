#include <iostream>

// This does work because single line comments are not affected by having
// nested /* */ symbols between them. This is because this type of comment
// does not terminate so there is no way to accidentally "terminate it early."

int main() {
    // This is a comment that extends over several lines
    // by using // at the beginning of each line instead of using /*
    // or */ to delimit comments.
    std::cout << "Does this work?" << std::endl;
    return 0;
}
