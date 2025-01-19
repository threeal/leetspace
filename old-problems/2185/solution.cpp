#include <string>
#include <vector>

class Solution {
 public:
  int prefixCount(std::vector<std::string>& words, std::string pref) {
    int count{0};
    for (const auto& word : words) {
      if (word.compare(0, pref.size(), pref) == 0) ++count;
    }
    return count;
  }
};
