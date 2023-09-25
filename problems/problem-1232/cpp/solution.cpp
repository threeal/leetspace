class Solution {
 public:
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    const auto x0 = coordinates[0][0];
    const auto y0 = coordinates[0][1];
    const auto w = coordinates[1][0] - x0;
    const auto h = coordinates[1][1] - y0;

    if (w == 0) {
      for (const auto coord : coordinates) {
        if (coord[0] != x0) return false;
      }
      return true;
    }

    const auto n = coordinates.size();
    for (size_t i = 2; i < n; ++i) {
      const auto x = coordinates[i][0] - x0;
      if (coordinates[i][1] - y0 != (x * h) / w) return false;
    }
    return true;
  }
};
