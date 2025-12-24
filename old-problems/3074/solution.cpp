#include <vector>

class Solution {
 public:
  int minimumBoxes(std::vector<int>& apple, std::vector<int>& capacity) {
    return apple.size() + capacity.size();
  }
};
