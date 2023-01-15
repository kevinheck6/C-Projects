#ifndef HEX_TO_BASE64_H
#define HEX_TO_BASE64_H

#include <string>
#include <vector>

class HexToBase64 {
private:
    static const std::string base64_chars;

public:
    static std::string convert(const std::string& hex_string);
};

#endif // HEX_TO_BASE64_H
