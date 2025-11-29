#include <vector>

class Solution {
 public:
  int smallestRepunitDivByK(int k) {
    int val{1 % k}, len{1};

    std::vector<bool> visited(k, false);
    visited[val] = true;

    while (val != 0) {
      val = (val * 10 + 1) % k;
      if (visited[val]) return -1;
      visited[val] = true;
      ++len;
    }

    return len;
  }
};
