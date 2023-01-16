#include "Conversion.h"

std::string Conversion::hex_to_binary(const std::string& hex_string) {
    std::string binary_string;
    for (char c : hex_string) {
        switch (c) {
            case '0': binary_string += "0000"; break;
            case '1': binary_string += "0001"; break;
            case '2': binary_string += "0010"; break;
            case '3': binary_string += "0011"; break;
            case '4': binary_string += "0100"; break;
            case '5': binary_string += "0101"; break;
            case '6': binary_string += "0110"; break;
            case '7': binary_string += "0111"; break;
            case '8': binary_string += "1000"; break;
            case '9': binary_string += "1001"; break;
            case 'a': case 'A': binary_string += "1010"; break;
            case 'b': case 'B': binary_string += "1011"; break;
            case 'c': case 'C': binary_string += "1100"; break;
            case 'd': case 'D': binary_string += "1101"; break;
            case 'e': case 'E': binary_string += "1110"; break;
            case 'f': case 'F': binary_string += "1111"; break;
            default: break;
        }
    }
    return binary_string;
}

std::string Conversion::binary_to_hex(const std::string& binary_string) {
    std::string hex_string;
    std::string temp;
    for (char c : binary_string) {
        temp += c;
        if (temp.size() == 4) {
            if (temp == "0000") hex_string += '0';
            else if (temp == "0001") hex_string += '1';
            else if (temp == "0010") hex_string += '2';
            else if (temp == "0011") hex_string += '3';
            else if (temp == "0100") hex_string += '4';
            else if (temp == "0101") hex_string += '5';
            else if (temp == "0110") hex_string += '6';
            else if (temp == "0111") hex_string += '7';
            else if (temp == "1000") hex_string += '8';
            else if (temp == "1001") hex_string += '9';
            else if (temp == "1010") hex_string += 'a';
            else if (temp == "1011") hex_string += 'b';
            else if (temp == "1100") hex_string += 'c';
            else if (temp == "1101") hex_string += 'd';
            else if (temp == "1110") hex_string += 'e';
            else if (temp == "1111") hex_string += 'f';
            temp.clear();
        }
    }
    return hex_string;
}

int Conversion::binary_to_decimal(const std::string& binary_string) {
    int decimal = 0;
    int base = 1;
    for (int i = binary_string.size() - 1; i >= 0; i--) {
        if (binary_string[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

std::string Conversion::decimal_to_binary(int decimal) {
    std::string binary_string;
    while (decimal > 0) {
        binary_string = std::to_string(decimal % 2) + binary_string;
        decimal /= 2;
    }
    return binary_string;
}
