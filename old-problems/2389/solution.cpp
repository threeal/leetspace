#include <vector>

class Solution {
 public:
  std::vector<int> answerQueries(
      std::vector<int>& nums, std::vector<int>& queries) {
    return nums.size() >= queries.size() ? nums : queries;
  }
};
