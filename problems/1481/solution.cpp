#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int findLeastNumOfUniqueInts(std::vector<int>& arr, int k) {
    std::unordered_map<int, int> uniqueCounts;
    for (const auto val : arr) {
      ++uniqueCounts[val];
    }

    std::vector<int> counts;
    counts.reserve(uniqueCounts.size());
    for (const auto [val, count] : uniqueCounts) {
      counts.push_back(count);
    }

    std::sort(counts.begin(), counts.end());

    auto it = counts.begin();
    while (it != counts.end() && k >= *it) {
      k -= *it;
      ++it;
    }

    return std::distance(it, counts.end());
  }
};
