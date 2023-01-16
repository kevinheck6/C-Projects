#include "HexToBase64.h"

const std::string HexToBase64::base64_chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

std::string HexToBase64::convert(const std::string& hex_string) {
    std::string binary_string = Conversion::hex_to_binary(hex_string);

    // Calculate the number of padding characters needed for base64
    int num_padding = (3 - (binary_string.size() / 8) % 3) % 3;
    // Add padding characters to the binary string
    binary_string.append(num_padding * 8, '0');

    // Create an empty string to store the base64 characters
    std::string base64_string;

    // Iterate through the binary string 24 bits at a time
    for (int i = 0; i < binary_string.size(); i += 24) {
        int byte1 = stoi(binary_string.substr(i, 8), nullptr, 2);
        int byte2 = stoi(binary_string.substr(i + 8, 8), nullptr, 2);
        int byte3 = stoi(binary_string.substr(i + 16, 8), nullptr, 2);

        // Get the index of the first base64 character
        int index1 = byte1 >> 2;
        // Get the index of the second base64 character
        int index2 = ((byte1 & 3) << 4) | (byte2 >> 4);
        // Get the index of the third base64 character
        int index3 = ((byte2 & 15) << 2) | (byte3 >> 6);
        // Get the index of the fourth base64 character
        int index4 = byte3 & 63;

        // Append the base64 characters to the string
        base64_string += base64_chars[index1];
        base64_string += base64_chars[index2];
        base64_string += base64_chars[index3];
        base64_string += base64_chars[index4];
    }

    // Add padding characters to the base64 string
    for (int i = 0; i < num_padding; i++) {
        base64_string[base64_string.size() - 1 - i] = '=';
    }

    // Return the base64 string
    return base64_string;
}
