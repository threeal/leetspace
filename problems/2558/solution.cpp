#include <cmath>
#include <queue>
#include <vector>

class Solution {
 public:
  long long pickGifts(std::vector<int>& gifts, int k) {
    std::priority_queue<int> richest{};
    for (const auto gift : gifts) richest.push(gift);

    while (k > 0) {
      richest.push(std::sqrt(richest.top()));
      richest.pop();
      --k;
    }

    long long total{0};
    while (!richest.empty()) {
      total += richest.top();
      richest.pop();
    }

    return total;
  }
};
