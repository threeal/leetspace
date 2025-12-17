#include <numeric>
#include <vector>

class Solution {
 public:
  int numOfSubarrays(std::vector<int>& arr, int k, int threshold) {
    threshold *= k;
    int sum{std::accumulate(arr.begin(), arr.begin() + k, 0)};
    int count{sum >= threshold ? 1 : 0};
    for (std::size_t i = k; i < arr.size(); ++i) {
      sum -= arr[i - k];
      sum += arr[i];
      if (sum >= threshold) ++count;
    }
    return count;
  }
};
