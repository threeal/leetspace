#include <vector>

class Solution {
 public:
  int maximumWealth(std::vector<std::vector<int>>& accounts) {
    int maxWealth{0};
    for (const std::vector<int>& account : accounts) {
      int wealth{0};
      for (const int amount : account) wealth += amount;
      if (wealth > maxWealth) maxWealth = wealth;
    }
    return maxWealth;
  }
};
