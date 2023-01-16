#include <iostream>
#include "Xor.h"

std::string Xor::fixed_xor(std::string hex_string1, std::string hex_string2) {
    if (hex_string1.length() != hex_string2.length()) {
        std::cout << "Error: Input hex strings must be of equal length" << std::endl;
        return "";
    }

    std::string binary_string1 = Conversion::hex_to_binary(hex_string1);
    std::string binary_string2 = Conversion::hex_to_binary(hex_string2);
    std::string xor_binary_string = "";

    for (int i = 0; i < binary_string1.length(); i++) {
        xor_binary_string += (binary_string1[i] == binary_string2[i]) ? '0' : '1';
    }

    return Conversion::binary_to_hex(xor_binary_string);
}
