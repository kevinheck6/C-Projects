#ifndef HEXTOBASE64_H
#define HEXTOBASE64_H

#include <string>
#include "Conversion.h"

class HexToBase64 {
public:
    static std::string convert(const std::string& hex_string);
private:
    static const std::string base64_chars;
};

#endif
