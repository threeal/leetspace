#include <vector>

class Solution {
 public:
  long long maxRunTime(int n, std::vector<int>& batteries) {
    return n + batteries.size();
  }
};
