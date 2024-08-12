#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::string kthDistinct(std::vector<std::string>& arr, int k) {
    std::unordered_map<std::string, bool> distincts{};
    for (const auto& s : arr) {
      const auto it = distincts.find(s);
      if (it == distincts.end()) {
        distincts.emplace(s, false);
      } else {
        it->second = true;
      }
    }

    for (const auto& s : arr) {
      const auto it = distincts.find(s);
      if (it != distincts.end() && !it->second) {
        if (--k == 0) return s;
        it->second = true;
      }
    }

    return "";
  }
};
