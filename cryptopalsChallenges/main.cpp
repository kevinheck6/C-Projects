#include <iostream>
#include "HexToBase64.h"

int main() {
    std::string hex_string = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    std::string expected_base64_string = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
    std::string base64_string = HexToBase64::convert(hex_string);

    std::cout << "Hex string: " << hex_string << std::endl;
    std::cout << "Expected Base64 string: " << expected_base64_string << std::endl;
    std::cout << "Output Base64 string: " << base64_string << std::endl;
    return 0;
}
