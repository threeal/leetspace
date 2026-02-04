#include <vector>

class Solution {
 public:
  bool mergeTriplets(
      std::vector<std::vector<int>>& triplets, std::vector<int>& target) {
    int flag{0};
    for (const auto& triplet : triplets) {
      if (triplet[0] <= target[0] && triplet[1] <= target[1] &&
          triplet[2] <= target[2]) {
        if (triplet[0] == target[0]) flag |= 1;
        if (triplet[1] == target[1]) flag |= 2;
        if (triplet[2] == target[2]) flag |= 4;
        if (flag == 7) return true;
      }
    }
    return false;
  }
};
