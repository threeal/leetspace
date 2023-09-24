class Solution {
 public:
  double champagneTower(int poured, int query_row, int query_glass) {
    int total = calculateTotal(query_row);
    if (poured <= total) {
      total -= query_row + 1;
      if (poured <= total) return 0.0;
      return (query_glass == 0 || query_glass == query_row)
          ? (poured - total) / (2.0 * query_row)
          : (poured - total) / (double)query_row;
    }
    return 1.0;
  }

  int calculateTotal(int row) {
    ++row;
    return row % 2 == 0
        ? (row + 1) * (row / 2)
        : (row + 1) * (row / 2) + (row / 2 + 1);
  }
};
