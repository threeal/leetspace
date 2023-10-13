class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    const auto n = cost.size();
    function<int(size_t)> fn = [&](size_t i) {
      if (i >= n) return 0;
      return cost[i] + min(fn(i + 1), fn(i + 2));
    };

    return min(fn(0), fn(1));
  }
};
