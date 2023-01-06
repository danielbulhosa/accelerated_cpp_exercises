#include <iostream> // Import always in its own line, required by language

int // Declaration can go in its own line
main // Function name can be in own line separate from declaration
( // Parameter parentheses can start in own line.
  // Paramters can be multiline hence we can have new line between parentheses.
        )
{ // Statement beginning can always be in new line

    // Each individual variable and operator can be in its own line as long as:
    // - Variable labels are not broken by new lines
    // - Strings are not broken by new lines (this owuld change the string)
    // - Operators are not broken by new lines
    // Note that even the scope operator can be on a separate line from each of its operands, just like the << operator!
    // Thus we can see that C++ is in fact quite flexible about whitespace, it carries little meaning in how statements
    // are read by the compiler beyond a few rules.
    std
    ::
    cout
    <<
    "Hello, World!"
    <<
    std
    ::
    endl
    ;
    return
    0
    ;
}
