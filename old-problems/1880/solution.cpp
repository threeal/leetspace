#include <string>

class Solution {
 public:
  bool isSumEqual(std::string firstWord, std::string secondWord, std::string targetWord) {
    return convert(firstWord) + convert(secondWord) == convert(targetWord);
  }

 private:
  int convert(const std::string& s) {
    int num{0};
    for (const char c : s) {
      num = num * 10 + c - 'a';
    }
    return num;
  }
};
