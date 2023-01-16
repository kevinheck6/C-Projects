#ifndef CONVERSION_H
#define CONVERSION_H

#include <string>

class Conversion {
public:
    static std::string hex_to_binary(const std::string& hex_string);
    static std::string binary_to_hex(const std::string& binary_string);
    static int binary_to_decimal(const std::string& binary_string);
    static std::string decimal_to_binary(int decimal);
};

#endif
