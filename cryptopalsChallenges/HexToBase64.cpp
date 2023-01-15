#include "HexToBase64.h"

// A string containing all the base64 characters
const std::string HexToBase64::base64_chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

// The function that converts hex string to base64
std::string HexToBase64::convert(const std::string& hex_string) {
    // Create an empty vector to store the hex bytes
    std::vector<int> hex_bytes;

    // Iterate through the hex string 2 characters at a time
    for (int i = 0; i < hex_string.size(); i += 2) {
        // Get the next two characters
        std::string byte = hex_string.substr(i, 2);
        // Convert the two characters to an integer and add it to the vector
        hex_bytes.push_back(strtol(byte.c_str(), nullptr, 16));
    }

    // Calculate the number of padding characters needed for base64
    int num_padding = static_cast<int>(3 - hex_bytes.size() % 3) % 3;
    // Resize the vector to include the padding characters
    hex_bytes.resize(hex_bytes.size() + num_padding, 0);

    // Create an empty string to store the base64 characters
    std::string base64_string;

    // Iterate through the vector 3 bytes at a time
    for (int i = 0; i < hex_bytes.size(); i += 3) {
        int a = hex_bytes[i];
        int b = hex_bytes[i + 1];
        int c = hex_bytes[i + 2];

        // Get the index of the first base64 character
        int index1 = a >> 2;
        // Get the index of the second base64 character
        int index2 = ((a & 3) << 4) | (b >> 4);
        // Get the index of the third base64 character
        int index3 = ((b & 15) << 2) | (c >> 6);
        // Get the index of the fourth base64 character
        int index4 = c & 63;

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

