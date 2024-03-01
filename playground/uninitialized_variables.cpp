#include <iostream>

int main() {
    // Declare variables of different basic types without initializing them
    int uninitInt;
    double uninitDouble;
    char uninitChar;
    bool uninitBool;

    // Print the values of uninitialized variables
    std::cout << "Uninitialized int: " << uninitInt << std::endl;
    std::cout << "Uninitialized double: " << uninitDouble << std::endl;
    std::cout << "Uninitialized char: " << uninitChar << std::endl;
    // Print uninitialized bool as integer to make its value clear (0 or non-0)
    std::cout << "Uninitialized bool: " << static_cast<int>(uninitBool) << std::endl;

    return 0;
}
