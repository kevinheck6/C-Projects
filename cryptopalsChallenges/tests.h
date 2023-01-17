#ifndef TESTS_H
#define TESTS_H

#include <iostream>

class Test {
public:
    static void run();
    static void test_hex_to_base64();
    static void test_fixed_xor();
    static void test_single_byte_xor_cipher();
};

#endif
