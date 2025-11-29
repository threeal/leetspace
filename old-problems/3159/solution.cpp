#include <vector>

class Solution {
 public:
  std::vector<int> occurrencesOfElement(
      std::vector<int>& nums, std::vector<int>& queries, int x) {
    int n{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      if (nums[i] == x) nums[n++] = i;
    }

    for (int& query : queries) {
      query = query <= n ? nums[query - 1] : -1;
    }

    return queries;
  }
};
