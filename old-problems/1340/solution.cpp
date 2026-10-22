#include <vector>

class Solution {
 public:
  int maxJumps(std::vector<int>& arr, int d) {
    int maxJump{0};
    std::vector<int> maxJumps(arr.size(), 0);
    for (std::size_t i{0}; i < arr.size(); ++i) {
      if (maxJumps[i] == 0) explore(maxJumps, arr, d, i);
      if (maxJumps[i] > maxJump) maxJump = maxJumps[i];
    }
    return maxJump;
  }

 private:
  static void explore(
      std::vector<int>& maxJumps, const std::vector<int>& arr,
      std::size_t d, std::size_t i) {
    int maxJump{0};

    const std::size_t l{i < d ? 0 : i - d};
    for (std::size_t j{i}; j > l;) {
      --j;
      if (arr[j] >= arr[i]) break;
      if (maxJumps[j] == 0) explore(maxJumps, arr, d, j);
      if (maxJumps[j] > maxJump) maxJump = maxJumps[j];
    }

    const std::size_t r{i + d < arr.size() ? i + d : arr.size() - 1};
    for (std::size_t j{i + 1}; j <= r; ++j) {
      if (arr[j] >= arr[i]) break;
      if (maxJumps[j] == 0) explore(maxJumps, arr, d, j);
      if (maxJumps[j] > maxJump) maxJump = maxJumps[j];
    }

    maxJumps[i] = 1 + maxJump;
  }
};
