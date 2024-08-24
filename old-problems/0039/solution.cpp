#include <span>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> combinationSum(
      std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> combinations{};
    std::vector<int> current{};
    fillCombinations(combinations, current, candidates, target);
    return combinations;
  }

  void fillCombinations(
      std::vector<std::vector<int>>& combinations,
      std::vector<int>& current,
      std::span<int> candidates,
      int target) {
    for (std::size_t i{0}; i < candidates.size(); ++i) {
      if (candidates[i] > target) continue;

      current.push_back(candidates[i]);
      if (candidates[i] == target) {
        combinations.push_back(current);
      } else {
        fillCombinations(
            combinations, current, candidates.subspan(i),
            target - candidates[i]);
      }
      current.pop_back();
    }
  }
};
