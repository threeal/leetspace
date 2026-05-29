#include <vector>

class Solution {
 public:
  long long minNumberOfSeconds(
      int mountainHeight, std::vector<int>& workerTimes) {
    return mountainHeight + workerTimes.size();
  }
};
