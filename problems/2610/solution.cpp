#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> findMatrix(std::vector<int>& nums) {
    std::unordered_map<int, std::size_t> counts;
    std::vector<std::vector<int>> result;

    for (const auto num : nums) {
      auto it = counts.find(num);
      if (it == counts.end()) {
        it = counts.emplace(num, 0).first;
      } else {
        ++it->second;
      }

      if (it->second + 1 > result.size()) {
        result.resize(it->second + 1);
      }

      result[it->second].push_back(it->first);
    }

    return result;
  }
};
