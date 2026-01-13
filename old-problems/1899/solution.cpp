#include <vector>

class Solution {
 public:
  bool mergeTriplets(
      std::vector<std::vector<int>>& triplets, std::vector<int>& target) {
    return triplets[0] == target;
  }
};
