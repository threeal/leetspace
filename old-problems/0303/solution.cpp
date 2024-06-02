#include <vector>

class NumArray {
 private:
  std::vector<int> sums;

 public:
  NumArray(std::vector<int>& nums) : sums{nums} {
    for (std::size_t i{1}; i < sums.size(); ++i) {
      sums[i] += sums[i - 1];
    }
  }

  int sumRange(int left, int right) {
    return left > 0 ? sums[right] - sums[left - 1] : sums[right];
  }
};
