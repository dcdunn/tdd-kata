#pragma once
#include <string>

class Soundex
{
   std::string zeroPad(const std::string& word);
   char head(const std::string& word);
   std::string tail(const std::string& word);
   char lower(char letter);
   std::string encodedDigits(const std::string& word, char last);
   std::string encodeDigit(char c);

public:
  std::string encode(const std::string& word);
};
