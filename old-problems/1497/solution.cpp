#include <vector>

class Solution {
 public:
  bool canArrange(std::vector<int>& arr, int k) {
    std::vector<int> mod(k, 0);
    for (const auto num : arr) ++mod[((num % k) + k) % k];

    if (mod[0] % 2 != 0) return false;
    if (k % 2 == 0 && mod[k / 2] % 2 != 0) return false;

    for (int i = 1; i < k - i; ++i) {
      if (mod[i] != mod[k - i]) return false;
    }

    return true;
  }
};
