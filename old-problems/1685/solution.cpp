// Here's the clue from the example:
//
// nums: [1, 4, 6, 8, 10]
// output: [24, 15, 13, 15, 21]
//
// The output[2] can be calculated as follows:
//
// output[2] = abs(1 - 6) + abs(4 - 6) + abs(6 - 6) + abs(8 - 6) + abs(10 - 6)
// output[2] = 5 + 2 + 2 + 4
// output[2] = 13
//
// But since we know the array is sorted, we can ignore absolute here by adjusting lhs and rhs accordingly:
//
// output[2] = (6 - 1) + (6 - 4) + (6 - 6) + (8 - 6) + (10 - 6)
//
// Or we can just simplify it like this:
//
// output[2] = (6 * 2) - (1 + 4) + (8 + 10) - (6 * 2)
// output[i] = (nums[i] * i) - leftTotal + rightTotal - (nums[i] * (n - i - 1))
//
// From that clue, we can solve this problem as follows:
// - Calculate the total, save it as the right total.
// - Iterate each element, shift the number from the right total to the left total.
// - Modify the element according to the above equation.
// - Return the modified array.

#include <vector>

class Solution {
 public:
  std::vector<int> getSumAbsoluteDifferences(std::vector<int>& nums) {
    // Calculate the right total.
    int rightTotal = 0;
    for (const auto num : nums) {
      rightTotal += num;
    }

    // Iterate each element to update the output.
    int leftTotal = 0;
    for (std::size_t i = 0; i < nums.size(); ++i) {
      // Shift value from the right total to the left total.
      leftTotal += nums[i];
      rightTotal -= nums[i];

      // Update the output.
      nums[i] = (nums[i] * (i + 1) - leftTotal) + (rightTotal - nums[i] * (nums.size() - i - 1));
    }

    // Return the modified array.
    return nums;
  }
};
