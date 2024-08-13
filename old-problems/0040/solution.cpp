#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> combinationSum2(
      std::vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());

    std::vector<std::vector<int>> combinations{};
    findCombinations(
        combinations, candidates.data(), candidates.size(), target);
    return combinations;
  }

  void findCombinations(
      std::vector<std::vector<int>>& combinations,
      int* candidates, int candidatesSize, int target) {
    for (int i{0}; i < candidatesSize; ++i) {
      if (candidates[i] > target) break;
      if (i < candidatesSize - 1 && candidates[i] == candidates[i + 1]) {
        continue;
      }

      if (candidates[i] == target) {
        combinations.push_back({candidates[i]});
      } else {
        std::size_t j{combinations.size()};
        findCombinations(combinations, candidates, i, target - candidates[i]);
        while (j < combinations.size()) {
          combinations[j].push_back(candidates[i]);
          ++j;
        }
      }
    }
  }
};
