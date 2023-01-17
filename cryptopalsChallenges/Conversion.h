#ifndef CONVERSION_H
#define CONVERSION_H

#include <string>

class Conversion {
public:
    static std::string hex_to_binary(const std::string& hex_string);
    static std::string binary_to_hex(const std::string& binary_string);
    static int binary_to_decimal(const std::string& binary_string);
    static std::string decimal_to_binary(int decimal);
    static std::string int_to_hex_string(int num);
    static std::string hex_to_string(const std::string& hex_string);
    static std::string int_to_hex_string(int num, int length);
    static std::string binary_to_string(const std::string& binary_string);
    static std::string int_to_binary(int number, int num_bits);
    static int hex_to_int(char hex_char);
    static int hex_to_int(const std::string& hex_string);
};

#endif
