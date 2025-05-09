#include <string>
#include <unordered_set>
#include <vector>

class Solution {
 private:
  static constexpr const char* morseMap[]{
      ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
      "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
      "..-", "...-", ".--", "-..-", "-.--", "--.."};

 public:
  int uniqueMorseRepresentations(std::vector<std::string>& words) {
    std::unordered_set<std::string> morses{};
    for (const std::string& word : words) {
      std::string morse{};
      for (const char c : word) morse += morseMap[c - 'a'];
      morses.insert(morse);
    }
    return morses.size();
  }
};
