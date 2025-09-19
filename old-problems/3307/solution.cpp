#include <vector>

class Solution {
 public:
  char kthCharacter(long long k, std::vector<int>& operations) {
    return k + operations.size();
  }
};
