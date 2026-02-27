#include <algorithm>
#include <string>

class Solution {
 public:
  int minOperations(std::string s, int k) {
    int zeros{0};
    for (char c : s) {
      if (c == '0') ++zeros;
    }

    if (zeros == 0) return 0;

    const int n = s.size();
    if (n == k) return zeros == k ? 1 : -1;

    const int ones{n - zeros};
    const int nk{n - k};

    int even{std::max((zeros + k - 1) / k, (zeros + nk - 1) / nk)};
    if (even % 2 == 1) ++even;

    if (k % 2 == zeros % 2) {
      int odd{std::max((zeros + k - 1) / k, (ones + nk - 1) / nk)};
      if (odd % 2 == 0) ++odd;
      return zeros % 2 == 0 ? std::min(even, odd) : odd;
    }

    return zeros % 2 == 0 ? even : -1;
  }
};
