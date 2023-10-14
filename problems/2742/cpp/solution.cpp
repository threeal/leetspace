class Solution {
 public:
  int paintWalls(vector<int>& cost, vector<int>& time) {
    const int n = min(cost.size(), time.size());

    auto cache = vector(n + 1, vector(n + 1, -1));
    const function<int(int, int)> fn = [&](int i, int left) -> int {
      if (left <= 0) return 0;
      if (i >= n) return 1'000'000'000;
      if (cache[i][left] >= 0) return cache[i][left];
      return cache[i][left] = min(
                 cost[i] + fn(i + 1, left - time[i] - 1),
                 fn(i + 1, left));
    };

    return fn(0, n);
  }
};
