#include <vector>

class Solution {
 public:
  int lenLongestFibSubseq(std::vector<int>& arr) {
    int longest{0};

    std::vector<std::vector<int>> counts(arr.size() - 1);
    for (std::size_t i{0}; i < counts.size(); ++i) {
      counts[i].resize(i + 1, 0);
    }

    for (std::size_t j{arr.size() - 2}; j > 0; --j) {
      for (std::size_t i{0}, k{i + 1}; i < j; ++i) {
        while (k < arr.size() && arr[i] + arr[j] > arr[k]) ++k;
        if (k < arr.size() && arr[i] + arr[j] == arr[k]) {
          counts[j - 1][i] = 1 + counts[k - 1][j];
          if (counts[j - 1][i] > longest) longest = counts[j - 1][i];
        }
      }
    }

    return longest > 0 ? 2 + longest : 0;
  }
};
