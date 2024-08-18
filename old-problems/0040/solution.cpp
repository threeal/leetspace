#include <algorithm>
#include <span>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> combinationSum2(
      std::vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());

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
    int prevCandidate{0};
    for (std::size_t i{0}; i < candidates.size(); ++i) {
      if (candidates[i] > target) break;

      if (candidates[i] == prevCandidate) continue;
      prevCandidate = candidates[i];

      current.push_back(candidates[i]);
      if (candidates[i] == target) {
        combinations.push_back(current);
      } else {
        fillCombinations(
            combinations, current, candidates.subspan(i + 1),
            target - candidates[i]);
      }
      current.pop_back();
    }
  }
};
