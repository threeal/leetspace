#include <unordered_map>
#include <vector>

int rev(int val);

class Solution {
 public:
  int countNicePairs(std::vector<int>& nums) {
    std::unordered_map<int, int> diffsCounts;
    for (const auto num : nums) {
      ++diffsCounts[num - rev(num)];
    }

    int totalCount = 0;
    for (const auto [diff, count] : diffsCounts) {
      totalCount += count * (count - 1) / 2;
    }

    return totalCount;
  }
};

int rev(int num) {
  int revNum = 0;
  while (num > 0) {
    revNum = revNum * 10 + num % 10;
    num /= 10;
  }

  return revNum;
}
