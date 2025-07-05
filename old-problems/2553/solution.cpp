#include <vector>

class Solution {
 public:
  std::vector<int> separateDigits(std::vector<int>& nums) {
    std::vector<int> output{};
    for (const int num : nums) {
      for (int exp{100000}; exp > 0; exp /= 10) {
        if (exp <= num) output.push_back(num / exp % 10);
      }
    }
    return output;
  }
};
