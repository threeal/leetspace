#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> groupStrs;

    for (const auto& str : strs) {
      auto key = str;
      std::sort(key.begin(), key.end());
      groupStrs[key].push_back(str);
    }

    std::vector<std::vector<std::string>> output;
    for (const auto& [key, strs] : groupStrs) {
      output.push_back(strs);
    }

    return output;
  }
};
