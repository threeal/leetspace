#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    int n{1};
    for (int i = nums.size(); i > 1; --i) n *= i;

    std::vector<std::vector<int>> output(n, nums);
    fill(output.data(), nums.size() - 1, nums);
    return output;
  }

  std::vector<int>* fill(std::vector<int>* out, int i, std::vector<int>& nums) {
    if (i == 0) {
      for (const auto num : nums) {
        if (num > 10) continue;
        (*out)[i] = num;
        ++out;
      }
      return out;
    }

    for (auto& num : nums) {
      if (num > 10) continue;

      num += 100;
      const auto end = fill(out, i - 1, nums);
      num -= 100;

      while (out != end) {
        (*out)[i] = num;
        ++out;
      }
    }

    return out;
  }
};
