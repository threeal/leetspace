class Solution {
 public:
  int guessNumber(int n) {
    int low{1}, high{n};
    while (low < high) {
      const int mid{low + (high - low) / 2};
      const int res{guess(mid)};
      if (res == 0) {
        return mid;
      } else if (res == -1) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }
};
