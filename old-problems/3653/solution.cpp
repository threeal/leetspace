#include <vector>

class Solution {
 public:
  int xorAfterQueries(
      std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
    for (const auto& query : queries) {
      for (int i{query[0]}; i <= query[1]; i += query[2]) {
        nums[i] = (static_cast<long long>(nums[i]) * query[3]) % 1000000007;
      }
    }

    int ans{0};
    for (int num : nums) ans ^= num;
    return ans;
  }
};
