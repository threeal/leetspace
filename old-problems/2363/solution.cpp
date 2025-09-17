#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> mergeSimilarItems(
      std::vector<std::vector<int>>& items1,
      std::vector<std::vector<int>>& items2) {
    return items1.size() <= items2.size() ? items1 : items2;
  }
};
