#include <string>
#include <vector>

class Solution {
 public:
  bool checkDistances(std::string s, std::vector<int>& distance) {
    for (std::size_t i{0}; i < s.size(); ++i) {
      if (distance[s[i] - 'a'] != -1) {
        const std::size_t j{i + distance[s[i] - 'a'] + 1};
        if (j >= s.size() || s[i] != s[j]) return false;
        distance[s[i] - 'a'] = -1;
      }
    }
    return true;
  }
};
