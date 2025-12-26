#include <vector>

class Solution {
 public:
  long long findTheArrayConcVal(std::vector<int>& nums) {
    long long sum{0};

    std::size_t l{0}, r{nums.size() - 1};
    while (l < r) {
      long long exp{10}, num = nums[r];
      while (exp <= num) exp *= 10;
      sum += exp * nums[l] + num;
      ++l, --r;
    }

    if (l == r) sum += nums[l];

    return sum;
  }
};
