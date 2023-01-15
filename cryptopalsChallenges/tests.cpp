#include "tests.h"
#include "HexToBase64.h"

void Test::run() {
    test_hex_to_base64();
}

void Test::test_hex_to_base64() {
    std::string hex_string = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    std::string expected_base64_string = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
    std::string base64_string = HexToBase64::convert(hex_string);

    if (base64_string == expected_base64_string) {
        std::cout << "HexToBase64 test passed" << std::endl;
    } else {
        std::cout << "HexToBase64 test failed: " << std::endl;
        std::cout << "Hex string: " << hex_string << std::endl;
        std::cout << "Expected Base64 string: " << expected_base64_string << std::endl;
        std::cout << "Output Base64 string: " << base64_string << std::endl;
    }
}
