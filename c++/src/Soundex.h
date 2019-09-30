#pragma once
#include <string>
#include <unordered_map>

const auto MaxCodeLength{ 4 };

class Soundex
{
   std::string zeroPad(const std::string& word)
   {
     const auto ZerosNeeded = MaxCodeLength - word.length();
     return word + std::string(ZerosNeeded, '0');
   }

   std::string head(const std::string& word)
   {
     return word.substr(0, 1);
   }

   std::string encodedDigits(const std::string& word)
   {
     auto encoded = std::string{};
     if (word.length() > 1) {
       encoded += encodeDigit(word[1]);
     }
     if (word.length() > 2) {
       encoded += encodeDigit(word[2]);
     }
     return encoded;
   }

   std::string encodeDigit(char c)
   {
     const std::unordered_map<char, std::string> codec{
       {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
       {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"},
       {'d', "3"}, {'t', "3"},
       {'l', "4"},
       {'m', "5"}, {'n', "5"},
       {'r', "6"}
     };
     const auto replacement = codec.find(c);
     if (replacement == codec.end()) return "";
     return replacement->second;
   }

public:
   std::string encode(const std::string& word)
   {
     return zeroPad(head(word) + encodedDigits(word));
   }
};
