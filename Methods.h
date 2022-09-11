#ifndef METHODS
#define METHODS
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <random>

#define EOF_STRING "zzzzzzzzzzzzzzzz"
#define GLOBAL_ARRAY 352461

#define WORD_LENGTH_3 3
#define WORD_LENGTH_4 4
#define WORD_LENGTH_5 5
#define WORD_LENGTH_6 6
#define WORD_LENGTH_7 7
#define WORD_LENGTH_8 8
#define WORD_LENGTH_9 9
#define WORD_LENGTH_10 10
#define WORD_LENGTH_11 11
#define WORD_LENGTH_12 12
#define WORD_LENGTH_13 13
#define WORD_LENGTH_14 14
#define WORD_LENGTH_15 15

bool Task1filter(std::string argv1, std::string argv2);
bool justAlphabets(std::string const &str);
bool comparator(std::string str1, std::string str2);
std::string* globalStringArray(std::string argv2);


#endif //methods
