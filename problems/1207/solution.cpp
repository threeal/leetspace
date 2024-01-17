#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  bool uniqueOccurrences(std::vector<int>& arr) {
    std::unordered_map<int, int> counts;
    for (const auto val : arr) {
      ++counts[val];
    }

    std::unordered_set<int> existingCounts;
    for (const auto [val, count] : counts) {
      if (!existingCounts.insert(count).second)
        return false;
    }

    return true;
  }
};
