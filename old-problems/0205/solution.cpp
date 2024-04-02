#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
 public:
  bool isIsomorphic(std::string s, std::string t) {
    std::unordered_map<char, char> map{};
    std::unordered_set<char> exist{};
    for (std::size_t i{0}; i < s.size(); ++i) {
      const auto it = map.find(s[i]);
      if (it == map.end()) {
        if (exist.contains(t[i])) {
          return false;
        } else {
          map.emplace(s[i], t[i]);
          exist.insert(t[i]);
        }
      } else if (t[i] != it->second) {
        return false;
      }
    }

    return true;
  }
};
