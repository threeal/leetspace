#include <vector>

class Solution {
 public:
  int minProcessingTime(
      std::vector<int>& processorTime, std::vector<int>& tasks) {
    return processorTime.size() + tasks.size();
  }
};
