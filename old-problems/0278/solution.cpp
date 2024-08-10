class Solution {
 public:
  int firstBadVersion(int n) {
    int i{1};
    while (i < n) {
      const int mid{i + (n - i) / 2};
      if (isBadVersion(mid)) {
        n = mid;
      } else {
        i = mid + 1;
      }
    }
    return n;
  }
};
