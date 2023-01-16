#include "tests.h"
#include "HexToBase64.h"
#include "Xor.h"

void Test::run() {
    test_hex_to_base64();
    test_fixed_xor();
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

void Test::test_fixed_xor() {
    std::string hex_string1 = "1c0111001f010100061a024b53535009181c";
    std::string hex_string2 = "686974207468652062756c6c277320657965";
    std::string expected_xor_hex = "746865206b696420646f6e277420706c6179";
    std::string xor_hex = Xor::fixed_xor(hex_string1, hex_string2);

    if (xor_hex == expected_xor_hex) {
        std::cout << "Fixed XOR test passed" << std::endl;
    } else {
        std::cout << "Fixed XOR test failed: " << std::endl;
        std::cout << "Input Hex String 1: " << hex_string1 << std::endl;
        std::cout << "Input Hex String 2: " << hex_string2 << std::endl;
        std::cout << "Expected XOR Hex: " << expected_xor_hex << std::endl;
        std::cout << "Output XOR Hex: " << xor_hex << std::endl;
    }
}
