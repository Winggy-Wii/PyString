#include "PyString.h"

int main() {
    // Create an instance of PyString and test the strip() function
    PyString str1("   Hello World!   ");
    auto res = str1.strip();
    std::cout << res << std::endl;

    // Test the split() function
    PyString str2("one,two,three");
    auto result = str2.split(",");
    std::cout << "Result after split: ";
    for (const auto& s : result) {
        std::cout << "'" << s << "' ";
    }
    std::cout << std::endl;

     // Create an instance of PyString
    PyString s1("hello");
    PyString s2("world");
    PyString s3("12345");
    PyString s4("123.456");
    PyString s5("HELLO");

    // Test display
    std::cout << "Display: ";
    s1.display();

    // Test operator+ and operator+=
    auto concatenated = s1 + s2;
    concatenated.display();
    s1 += s2;
    s1.display();

    // Test relational operators
    std::cout << "s1 > s2: " << (s1 > s2) << std::endl;
    std::cout << "s1 < s2: " << (s1 < s2) << std::endl;
    std::cout << "s1 == s2: " << (s1 == s2) << std::endl;
    std::cout << "s1 >= s2: " << (s1 >= s2) << std::endl;
    std::cout << "s1 <= s2: " << (s1 <= s2) << std::endl;

    // Test subscript operator for access
    std::cout << "s1[0]: " << s1[0] << std::endl;

    // Test subscript operator for slicing
    PyString s6("hello world");
    std::cout << "Slice s6[0:5]: " << s6["0:5"] << std::endl;

    // Test capitalize, upper, lower, title
    std::cout << "Capitalize: " << s1.capitalize() << std::endl;
    std::cout << "Upper: " << s1.upper() << std::endl;
    std::cout << "Lower: " << s5.lower() << std::endl;
    std::cout << "Title: " << s6.title() << std::endl;

    // Test strip, split, replace
    PyString s7("   spaced   ");
    std::cout << "Strip: '" << s7.strip() << "'" << std::endl;
    auto parts = s6.split(" ");
    std::cout << "Split: ";
    for (const auto& part : parts) {
        std::cout << "'" << part << "' ";
    }
    std::cout << std::endl;
    std::cout << "Replace: " << s6.replace("world", "there") << std::endl;

    // Test isalpha, isAscii, isdigit, etc.
    std::cout << "isAlpha: " << s1.isalpha() << std::endl;
    std::cout << "isAscii: " << s1.isAscii() << std::endl;
    std::cout << "isDigit: " << s3.isdigit() << std::endl;
    std::cout << "isDecimal: " << s3.isdecimal() << std::endl;
    std::cout << "isNumeric: " << s3.isnumeric() << std::endl;
    std::cout << "isFloat: " << s4.isFloat() << std::endl;

    // Test isupper, islower
    std::cout << "isUpper: " << s5.isupper() << std::endl;
    std::cout << "isLower: " << s1.islower() << std::endl;

    // Test append
    s1.append(s2);
    s1.display();

    // Test reverse
    s1.reverse();
    s1.display();

    // Test pop
    s1.pop();
    s1.display();
    s1.pop(2);
    s1.display();

    // Test length and sorted
    std::cout << "Length of s1: " << len(s1) << std::endl;
    std::cout << "Sorted s1: " << sorted(s1) << std::endl;

    // Test converting to int and float
    try {
        std::cout << "Convert to int: " << Int(s3) << std::endl;
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

    try {
        std::cout << "Convert to float: " << Float(s4) << std::endl;
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

    return 0;

}