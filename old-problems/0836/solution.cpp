#include <vector>

class Solution {
 public:
  bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2) {
    return rec1.size() == rec2.size();
  }
};
