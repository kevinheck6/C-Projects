#include <sstream>
#include <iomanip>
#include <bitset>
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

std::string Conversion::int_to_hex_string(int num) {
    std::stringstream stream;
    stream << std::hex << num;
    return stream.str();
}

std::string Conversion::hex_to_string(const std::string& hex_string) {
    std::stringstream ss;
    for (size_t i = 0; i < hex_string.length(); i += 2) {
        std::string byte = hex_string.substr(i, 2);
        char chr = (char) (int)strtol(byte.c_str(), NULL, 16);
        ss << chr;
    }
    return ss.str();
}


std::string Conversion::int_to_hex_string(int num, int length) {
    std::stringstream stream;
    stream << std::hex << num;
    std::string result(stream.str());
    if (result.length() < length) {
        result = std::string(length - result.length(), '0') + result;
    }
    return result;
}

std::string Conversion::int_to_binary(int number, int num_bits) {
    std::string binary_string = "";
    for (int i = num_bits - 1; i >= 0; i--) {
        binary_string += (number & (1 << i)) ? '1' : '0';
    }
    return binary_string;
}

std::string Conversion::binary_to_string(const std::string& binary_string) {
    std::string str;
    for (int i = 0; i < binary_string.length(); i += 8) {
        std::string byte = binary_string.substr(i, 8);
        int ascii_val = binary_to_decimal(byte);
        str += (char)ascii_val;
    }
    return str;
}

int Conversion::hex_to_int(const std::string& hex_string) {
    int num = 0;
    for (char c : hex_string) {
        num = num * 16 + hex_to_int(c);
    }
    return num;
}

int Conversion::hex_to_int(const char hex_char) {
    if (hex_char >= '0' && hex_char <= '9') {
        return hex_char - '0';
    }
    if (hex_char >= 'a' && hex_char <= 'f') {
        return hex_char - 'a' + 10;
    }
    if (hex_char >= 'A' && hex_char <= 'F') {
        return hex_char - 'A' + 10;
    }
    return 0;
}
