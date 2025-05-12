#include <vector>

class Solution {
 public:
  std::vector<int> findEvenNumbers(std::vector<int>& digits) {
    std::vector<int> output{};

    int freqs[10]{0};
    for (const int digit : digits) ++freqs[digit];

    for (int i{1}; i < 10; ++i) {
      if (freqs[i] == 0) continue;
      --freqs[i];
      for (int j{0}; j < 10; ++j) {
        if (freqs[j] == 0) continue;
        --freqs[j];
        for (int k{0}; k < 10; k += 2) {
          if (freqs[k] == 0) continue;
          output.push_back(i * 100 + j * 10 + k);
        }
        ++freqs[j];
      }
      ++freqs[i];
    }

    return output;
  }
};
