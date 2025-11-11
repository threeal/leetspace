#include <string>
#include <unordered_set>

class Solution {
 public:
  std::string findLexSmallestString(std::string s, int a, int b) {
    std::unordered_set<std::string> visited{};
    std::string smallest{s};
    find(visited, smallest, s, a, b);
    return smallest;
  }

 private:
  void find(
      std::unordered_set<std::string>& visited, std::string& smallest,
      const std::string& s, int a, int b) {
    std::string s1{s};
    for (std::size_t i{0}; i < s1.size(); ++i) {
      s1[i] = s[(s1.size() + i - b) % s1.size()];
    }

    if (!visited.contains(s1)) {
      visited.insert(s1);
      if (s1 < smallest) smallest = s1;
      find(visited, smallest, s1, a, b);
    }

    std::string s2(s);
    for (std::size_t i{1}; i < s2.size(); i += 2) {
      s2[i] = '0' + (s2[i] + a - '0') % 10;
    }

    if (!visited.contains(s2)) {
      visited.insert(s2);
      if (s2 < smallest) smallest = s2;
      find(visited, smallest, s2, a, b);
    }
  }
};
