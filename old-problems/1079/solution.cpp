#include <string>
#include <vector>

class Solution {
 public:
  int numTilePossibilities(std::string tiles) {
    std::vector<int> freqs(26, 0);
    for (const auto c : tiles) ++freqs[c - 'A'];

    std::size_t freqsSize{0};
    for (const auto freq : freqs) {
      if (freq > 0) freqs[freqsSize++] = freq;
    }
    freqs.resize(freqsSize);

    int count{0};
    for (std::size_t n{1}; n <= tiles.size(); ++n) {
      count += countPossibilities(n, freqs);
    }

    return count;
  }

 private:
  int countPossibilities(std::size_t n, std::vector<int>& freqs) {
    int count{0};
    if (n == 1) {
      for (const auto freq : freqs) {
        if (freq > 0) ++count;
      }
    } else {
      for (auto& freq : freqs) {
        if (freq == 0) continue;
        --freq;
        count += countPossibilities(n - 1, freqs);
        ++freq;
      }
    }
    return count;
  }
};
