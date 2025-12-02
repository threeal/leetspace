#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> intervalIntersection(
      std::vector<std::vector<int>>& firstList,
      std::vector<std::vector<int>>& secondList) {
    return firstList.size() <= secondList.size() ? firstList : secondList;
  }
};
