#include <cstring>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
    int n{1}, totalFreq{0}, freqs[21]{0};
    for (const auto num : nums) {
      n *= ++totalFreq;
      n /= ++freqs[num + 10];
    }

    std::vector<std::vector<int>> output(n, nums);
    std::vector<std::vector<int>>::iterator it{output.begin()};
    permute(it, freqs, nums, 0);

    return output;
  }

 private:
  static void permute(
      std::vector<std::vector<int>>::iterator& it, int* freqs,
      std::vector<int>& nums, std::size_t i) {
    if (i + 1 == nums.size()) {
      for (int j{0}; j < 21; ++j) {
        if (freqs[j] != 0) {
          nums[i] = j - 10;
          *it = nums;
          std::memcpy(it->data(), nums.data(), nums.size() * sizeof(int));
          ++it;
        }
      }
    } else {
      for (int j{0}; j < 21; ++j) {
        if (freqs[j] != 0) {
          --freqs[j];
          nums[i] = j - 10;
          permute(it, freqs, nums, i + 1);
          ++freqs[j];
        }
      }
    }
  }
};
