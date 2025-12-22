#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> combinationSum3(int k, int n) {
    std::vector<std::vector<int>> output{};
    std::vector<int> nums{};

    const int max{n < 9 ? n : 9};
    for (int num{1}; num <= max; ++num) {
      nums.push_back(num);
      find(output, nums, k - 1, n - num);
      nums.pop_back();
    }

    return output;
  }

 private:
  static void find(
      std::vector<std::vector<int>>& output,
      std::vector<int>& nums, int k, int n) {
    if (k == 1) {
      if (n <= 9 && n > nums.back()) {
        nums.push_back(n);
        output.push_back(nums);
        nums.pop_back();
      }
    } else {
      const int max{n < 9 ? n : 9};
      for (int num{nums.back() + 1}; num <= max; ++num) {
        nums.push_back(num);
        find(output, nums, k - 1, n - num);
        nums.pop_back();
      }
    }
  }
};
