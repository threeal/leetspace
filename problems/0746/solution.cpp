class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    const auto n = cost.size();
    vector<int> cache(n, -1);

    function<int(size_t)> fn = [&](size_t i) {
      if (i >= n) return 0;
      if (cache[i] < 0) {
        cache[i] = cost[i] + min(fn(i + 1), fn(i + 2));
      }
      return cache[i];
    };

    return min(fn(0), fn(1));
  }
};
