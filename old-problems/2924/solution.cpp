#include <vector>

class Solution {
 public:
  int findChampion(int n, std::vector<std::vector<int>>& edges) {
    return n * edges.size();
  }
};
