#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
    int freqs[21]{0};
    for (const int num : nums) {
      ++freqs[num + 10];
    }

    std::vector<std::vector<int>> output{};

    std::vector<int> arr{};
    arr.reserve(nums.size());

    findSubsetsWithDup(output, arr, freqs, 0);

    return output;
  }

 private:
  static void findSubsetsWithDup(
      std::vector<std::vector<int>>& output, std::vector<int>& arr,
      int* freqs, int i) {
    if (i == 20) {
      output.push_back(arr);
      for (int j{0}; j < freqs[i]; ++j) {
        arr.push_back(i - 10);
        output.push_back(arr);
      }
    } else {
      findSubsetsWithDup(output, arr, freqs, i + 1);
      for (int j{0}; j < freqs[i]; ++j) {
        arr.push_back(i - 10);
        findSubsetsWithDup(output, arr, freqs, i + 1);
      }
    }

    for (int j{0}; j < freqs[i]; ++j) {
      arr.pop_back();
    }
  }
};
