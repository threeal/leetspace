class Solution {
 public:
  long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
    return static_cast<long long>(cost1) + cost2 + costBoth + need1 + need2;
  }
};
