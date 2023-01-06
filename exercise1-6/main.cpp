#include <iostream>
#include <string>

int main() {
    /* If we type in `Samuel Beckett` both times we are asked for input
     * we will pass the name `Samuel` to the program twice. This is because
     * std::cin >> takes the first contiguous set of non-whitespace characters
     * and passes them into the program. In both cases this would be `Samuel`.
     *
     * I was WRONG! What actually happens is that `Beckett` is saved into the
     * input buffer and when input is requested again instead of getting a
     * prompt the program uses `Beckett` for the second input. Thus the `;`
     * at the end of the first input does not discard the rest of the buffer.
     * The buffer object still exists and contains the remaining input. All
     * that gets discarded by ; is the std::cin name.
     */

    std::cout << "What is your name? ";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name
              << std::endl << "And what is yours? ";
    std::cin >> name;
    std::cout << "Hello, " << name
              << "; nice to meet you too!" << std::endl;

    return 0;
}
