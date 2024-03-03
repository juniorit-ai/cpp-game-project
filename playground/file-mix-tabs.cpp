#include <iostream>

int main() {
    // Integer Literals
    int decimal_number = 42;        // Decimal (base 10)
	int octal_number = 052;         // Octal (base 8), prefix with 0
    int hexadecimal_number = 0x2A;  // Hexadecimal (base 16), prefix with 0x

    // Floating-point Literals
	float float_number = 3.14159f;  // Suffix 'f' for float
    double double_number = 2.71828; // Default is double

    // Character Literals
	char single_character = 'A';    // Enclosed in single quotes

    // String Literals
    std::string message = "Hello, World!"; // Enclosed in double quotes

    // Boolean Literals
	bool is_true = true;
    bool is_false = false;

    // Print the values
	std::cout << "Integer Literals: " << decimal_number << ", " 
              << octal_number << ", " << hexadecimal_number << std::endl;
	std::cout << "Floating-point Literals: " << float_number << ", " 
              << double_number << std::endl;
	std::cout << "Character Literal: " << single_character << std::endl;
    std::cout << "String Literal: " << message << std::endl;
    std::cout << "Boolean Literals: " << is_true << ", " << is_false << std::endl; 

    return 0;
}
