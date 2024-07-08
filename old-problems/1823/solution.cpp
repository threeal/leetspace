#include <vector>

class Solution {
 public:
  int findTheWinner(int n, int k) {
    std::vector<int> friends(n);
    for (int i{n}; i > 0; --i) friends[i - 1] = i;

    int begin{0};
    int end{0};

    int left{n};
    while (--left > 0) {
      for (int i{k}; i > 1; --i) {
        friends[end] = friends[begin];
        if (++begin >= n) begin = 0;
        if (++end >= n) end = 0;
      }
      if (++begin >= n) begin = 0;
    }

    return friends[begin];
  }
};
