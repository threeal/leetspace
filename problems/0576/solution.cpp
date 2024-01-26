class Solution {
 public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    return m + n + maxMove + startRow + startColumn;
  }
};
