#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "main.cpp"

TEST(cryptanalysis, test_1)
{
    std::istringstream iss("3\nThis is a test.\nCount me 1 2 3 4 5.\nWow!!!! Is this question easy?\n");
    std::ostringstream oss;

    cryptanalysis(iss, oss);

    EXPECT_EQ("S 7\n"
              "T 6\n"
              "I 5\n"
              "E 4\n"
              "O 3\n"
              "A 2\n"
              "H 2\n"
              "N 2\n"
              "U 2\n"
              "W 2\n"
              "C 1\n"
              "M 1\n"
              "Q 1\n"
              "Y 1\n",
              oss.str());
}

TEST(cryptanalysis, test_uDebug)
{
    std::ifstream input_file("test_uDebug.txt");
    std::ostringstream oss;

    cryptanalysis(input_file, oss);

    EXPECT_EQ("E 115\n"
              "T 66\n"
              "R 61\n"
              "A 56\n"
              "N 55\n"
              "O 54\n"
              "I 52\n"
              "S 51\n"
              "D 36\n"
              "H 33\n"
              "M 32\n"
              "L 30\n"
              "U 25\n"
              "Y 22\n"
              "C 18\n"
              "P 17\n"
              "F 10\n"
              "W 10\n"
              "B 8\n"
              "G 8\n"
              "V 8\n"
              "J 4\n"
              "X 4\n"
              "K 3\n"
              "Q 3\n"
              "Z 1\n",
              oss.str());
}
