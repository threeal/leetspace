class Solution {
 public:
  int countGoodStrings(int low, int high, int zero, int one) {
    int counts[100001];
    counts[0] = 1;

    for (int i{1}; i <= high; ++i) {
      int count{1};
      if (i >= zero) count += counts[i - zero];
      if (i >= one) count += counts[i - one];
      counts[i] = count % 1000000007;
    }

    return (1000000007 + counts[high] - counts[low - 1]) % 1000000007;
  }
};
