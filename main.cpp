#include <iostream>
#include <vector>
#include <algorithm>

#ifdef GTEST
#include <gtest/gtest.h>
#endif

#define ASCII_UPPERCASE_A 65
#define ASCII_LOWERCASE_A 97
#define ASCII_UPPERCASE_Z 90
#define ASCII_LOWERCASE_Z 122

void count_characters(int line_number, int ascii_table[], std::istream &is)
{
    std::string input;
    for (int num = 0; num < line_number; num++) {
        std::getline(is, input);
        for (int i = 0; i < input.length(); i++) {
            int ascii_number = input[i];
            if (ascii_number >= ASCII_UPPERCASE_A && ascii_number <= ASCII_UPPERCASE_Z)
                ascii_table[ascii_number - ASCII_UPPERCASE_A]++;

            if (ascii_number >= ASCII_LOWERCASE_A && ascii_number <= ASCII_LOWERCASE_Z)
                ascii_table[ascii_number - ASCII_LOWERCASE_A]++;
        }
    }
}

struct output_pair_t {
    char character;
    int count;
};

bool pair_compare(output_pair_t &p1, output_pair_t &p2)
{
    if (p1.count == p2.count)
        return p1.character < p2.character;
    else
        return p1.count > p2.count;
}

bool cryptanalysis(std::istream &is, std::ostream &os)
{
    std::string input;
    std::getline(is, input);

    int line_number = std::stoi(input);
    if (line_number <= 0)
        return false;

    int ascii_table[26] = { 0 };
    count_characters(line_number, ascii_table, is);

    std::vector< output_pair_t > pairs_vec;
    output_pair_t output_pair;

    for (int i = 0; i < 26; i++) {
        if (ascii_table[i] != 0) {
            output_pair.character = char(ASCII_UPPERCASE_A + i);
            output_pair.count = ascii_table[i];
            pairs_vec.push_back(output_pair);
        }
    }

    std::sort(pairs_vec.begin(), pairs_vec.end(), pair_compare);

    for (std::vector< output_pair_t >::iterator it = pairs_vec.begin(); it != pairs_vec.end(); ++it) {
        os << it->character << " " << it->count << std::endl;
    }

    return true;
}

int main(int argc, char **argv)
{

#ifdef GTEST
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#endif

    cryptanalysis(std::cin, std::cout);

    return 0;
}
