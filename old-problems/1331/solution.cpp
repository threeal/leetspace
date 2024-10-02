#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> arrayRankTransform(std::vector<int>& arr) {
    std::vector<int> idxs(arr.size());
    std::iota(idxs.begin(), idxs.end(), 0);

    std::sort(idxs.begin(), idxs.end(), [&arr](int a, int b) {
      return arr[a] < arr[b];
    });

    int prev{-1};
    int rank{0};
    for (const auto idx : idxs) {
      if (arr[idx] != prev) {
        prev = arr[idx];
        ++rank;
      }
      arr[idx] = rank;
    }

    return arr;
  }
};
