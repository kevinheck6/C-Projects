#include <iostream>
#include "SingleByteXorCipher.h"

SingleByteXorCipher::SingleByteXorCipher() {
    // Initialize the character frequency map
    charFrequency['a'] = 0.08167;
    charFrequency['b'] = 0.01492;
    charFrequency['c'] = 0.02782;
    charFrequency['d'] = 0.04253;
    charFrequency['e'] = 0.12702;
    charFrequency['f'] = 0.02228;
    charFrequency['g'] = 0.02015;
    charFrequency['h'] = 0.06094;
    charFrequency['i'] = 0.06966;
    charFrequency['j'] = 0.00153;
    charFrequency['k'] = 0.00772;
    charFrequency['l'] = 0.04025;
    charFrequency['m'] = 0.02406;
    charFrequency['n'] = 0.06749;
    charFrequency['o'] = 0.07507;
    charFrequency['p'] = 0.01929;
    charFrequency['q'] = 0.00095;
    charFrequency['r'] = 0.05987;
    charFrequency['s'] = 0.06327;
    charFrequency['t'] = 0.09056;
    charFrequency['u'] = 0.02758;
    charFrequency['v'] = 0.00978;
    charFrequency['w'] = 0.02360;
    charFrequency['x'] = 0.00150;
    charFrequency['y'] = 0.01974;
    charFrequency['z'] = 0.00074;

}

std::string SingleByteXorCipher::encrypt(std::string plaintext, char key) {
    std::string ciphertext;
    for (unsigned int i = 0; i < plaintext.length(); i++) {
        ciphertext += plaintext[i] ^ key;
    }
    return ciphertext;
}

std::string SingleByteXorCipher::decrypt(std::string ciphertext, char key) {
    std::string plaintext = decodeHex(ciphertext);
    return encrypt(plaintext, key);
}

double SingleByteXorCipher::score(std::string text) {
    double score = 0;
    for (unsigned int i = 0; i < text.length(); i++) {
        char c = tolower(text[i]);
        if (charFrequency.count(c) > 0) {
            score += charFrequency[c];
        }
    }
    return score;
}

std::string SingleByteXorCipher::decodeHex(std::string hexString) {
    std::string plainText;
    for (size_t i = 0; i < hexString.size(); i += 2) {
        std::string byte = hexString.substr(i, 2);
        char ch = static_cast<char>(std::stoi(byte, nullptr, 16));
        plainText += ch;
    }
    return plainText;
}

