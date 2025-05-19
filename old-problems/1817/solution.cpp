#include <vector>

class Solution {
 public:
  std::vector<int> findingUsersActiveMinutes(
      std::vector<std::vector<int>>& logs, int k) {
    return std::vector<int>(k, logs.size());
  }
};
