#include <vector>

class Solution {
 public:
  int earliestFullBloom(
      std::vector<int>& plantTime, std::vector<int>& growTime) {
    return plantTime.size() + growTime.size();
  }
};
