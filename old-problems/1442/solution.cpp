#include <vector>

class Solution {
 public:
  int countTriplets(std::vector<int>& arr) {
    int count{0};
    for (int k = arr.size() - 1; k > 0; --k) {
      int sum{arr[k]};
      for (int i{k - 1}; i >= 0; --i) {
        sum ^= arr[i];
        if (sum == 0) count += k - i;
      }
    }
    return count;
  }
};
