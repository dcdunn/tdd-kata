#include "Soundex.h"
#include <cctype>
#include <map>

const auto MaxCodeLength{ 4 };

 std::string Soundex::zeroPad(const std::string& word)
 {
   const auto ZerosNeeded = MaxCodeLength - word.length();
   return word + std::string(ZerosNeeded, '0');
 }

 char Soundex::head(const std::string& word)
 {
   return static_cast<char>(toupper(word.front()));
 }

 std::string Soundex::tail(const std::string& word)
 {
   return word.substr(1);
 }

 char Soundex::lower(char letter)
 {
   return static_cast<char>(tolower(letter));
 }

 std::string Soundex::encodedDigits(const std::string& word, char last)
 {
   auto encoded = std::string{};
   for (auto letter : word) {
     if (encoded.size() == MaxCodeLength-1) {
       return encoded;
     }
     letter = lower(letter);
     if (letter == 'w' || letter == 'h') {
       continue;
     }
     if (letter != last) {
       encoded += encodeDigit(letter);
     }
     last = letter;
   }
   return encoded;
 }

 std::string Soundex::encodeDigit(char c)
 {
   const std::map<char, std::string> codec{
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

 std::string Soundex::encode(const std::string& word)
 {
   return zeroPad(head(word) + encodedDigits(tail(word), lower(word.front())));
 }

