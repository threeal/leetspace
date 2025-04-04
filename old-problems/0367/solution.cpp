class Solution {
 public:
  bool isPerfectSquare(int num) {
    int low{1}, high{num};
    while (low < high) {
      const int mid{low + (high - low) / 2};
      if (num / mid > mid) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return num / low == low && num % low == 0;
  }
};
