#include <iostream>

/*
 * This program will work because:
 * - Whitespace (or lack thereof) has no effect in how C++ is parsed and compiled.
 * - Redundant brackets defining a scope do not affect the semantics of a statement. All that is required is AT LEAST
 *   one set of brackets to define the scope of a function, which are present here.
 */

int main() {{{{{{ std::cout << "Hello, World!" << std::endl; return 0; }}}}}}
