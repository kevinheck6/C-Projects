#ifndef SINGLEBYTEXORCIPHER_H
#define SINGLEBYTEXORCIPHER_H

#include <string>
#include <map>

class SingleByteXorCipher {
public:
    SingleByteXorCipher();
    std::string encrypt(std::string plaintext, char key);
    std::string decrypt(std::string ciphertext, char key);
    double score(std::string text);
    static std::string decodeHex(std::string hexString);

private:
    std::map<char, double> charFrequency;
};

#endif

