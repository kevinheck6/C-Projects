cmake_minimum_required(VERSION 3.23)
project(cryptopalsChallenges)

set(CMAKE_CXX_STANDARD 20)

add_executable(cryptopalsChallenges main.cpp HexToBase64.cpp HexToBase64.h tests.cpp tests.h xor.cpp xor.h Conversion.cpp Conversion.h SingleByteXorCipher.cpp SingleByteXorCipher.h)
