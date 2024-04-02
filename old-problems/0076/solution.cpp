#include <functional>
#include <string>
#include <unordered_map>

class Solution {
 public:
  std::string minWindow(std::string s, std::string t) {
    std::unordered_map<char, int> charsCounts;
    for (const auto c : t) {
      ++charsCounts[c];
    }

    std::function<int(

    return s + t;
  }
};
