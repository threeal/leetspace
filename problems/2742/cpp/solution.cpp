class Solution {
 public:
  int paintWalls(vector<int>& cost, vector<int>& time) {
    const int n = min(cost.size(), time.size());

    const function<int(int, int)> fn = [&](int i, int left) -> int {
      if (left <= 0) return 0;
      if (i >= n) return 1'000'000'000;
      return min(
          cost[i] + fn(i + 1, left - time[i] - 1),
          fn(i + 1, left));
    };

    return fn(0, n);
  }
};
