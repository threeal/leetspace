// First of all, nice pairs is if:
//
//   nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
//
// Let's adjust the equation to be:
//
//   nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
//
// So, since everything is in `num - rev(num)`, we can just iterate over each number
// and then store the count of each result of `num - rev(num)`.
//
// After counting each result, we can just sum them together using:
//
//   n * (n - 1) / 2
//
// And don't forget to divide it by modulo 10e9+7

#include <unordered_map>
#include <vector>

int rev(int val);

class Solution {
 public:
  int countNicePairs(std::vector<int>& nums) {
    // Count the number of the same result of `num - rev(num)`.
    std::unordered_map<int, long> diffsCounts;
    for (const auto num : nums) {
      ++diffsCounts[num - rev(num)];
    }

    // Calculate the total of each result count using `n * (n - 1) / 2`
    // and divide it by modulo 10e9+7.
    long totalCount = 0;
    for (const auto [diff, count] : diffsCounts) {
      totalCount += count * (count - 1) / 2;
      totalCount %= 1000000007;
    }

    return totalCount;
  }
};

// This function will reverse the number.
// For example 24 will be reversed to 42.
int rev(int num) {
  int revNum = 0;
  while (num > 0) {
    revNum = revNum * 10 + num % 10;
    num /= 10;
  }

  return revNum;
}
