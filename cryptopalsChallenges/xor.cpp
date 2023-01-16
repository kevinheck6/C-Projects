#include <iostream>
#include "Xor.h"

std::string Xor::fixed_xor(std::string hex_string1, std::string hex_string2) {
    // Check if the input hex strings are of equal length
    if (hex_string1.length() != hex_string2.length()) {
        std::cout << "Error: Input hex strings must be of equal length" << std::endl;
        return "";
    }

    // Convert the input hex strings to binary
    std::string binary_string1 = Conversion::hex_to_binary(hex_string1);
    std::string binary_string2 = Conversion::hex_to_binary(hex_string2);
    std::string xor_binary_string = "";

    // Perform the XOR operation on each corresponding bit of the input binary strings
    for (int i = 0; i < binary_string1.length(); i++) {
        xor_binary_string += (binary_string1[i] == binary_string2[i]) ? '0' : '1';
    }

    // Convert the resulting binary string to hex
    return Conversion::binary_to_hex(xor_binary_string);
}
