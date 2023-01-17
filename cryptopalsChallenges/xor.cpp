#include <iostream>
#include <iomanip>
#include "Xor.h"

std::string Xor::fixed_xor(std::string hex_string1, std::string hex_string2) {
    // Check if the input hex strings are of equal length
    if (hex_string1.length() != hex_string2.length()) {
        std::cout << "Error: Input hex strings must be of equal length" << std::endl;
        return "";
    }

    std::string xor_hex_string = "";

    // Perform the XOR operation on each corresponding character of the input hex strings
    for (int i = 0; i < hex_string1.length(); i++) {
        int val1 = std::stoi(hex_string1.substr(i, 1), nullptr, 16);
        int val2 = std::stoi(hex_string2.substr(i, 1), nullptr, 16);
        int xor_val = val1 ^ val2;

        // Append the result to the output hex string
        std::stringstream ss;
        ss << std::setw(1) << std::setfill('0') << std::hex << xor_val;
        xor_hex_string += ss.str();
    }

    return xor_hex_string;
}
