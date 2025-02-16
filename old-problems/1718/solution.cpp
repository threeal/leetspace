#include <vector>

class Solution {
 public:
  std::vector<int> constructDistancedSequence(int n) {
    std::vector<bool> exists(n + 1, false);
    std::vector<int> output(n * 2 - 1, 0);
    construct(n, exists, output, 0);
    return output;
  }

 private:
  bool construct(
      int n, std::vector<bool>& exists,
      std::vector<int>& output, std::size_t pos) {
    while (pos < output.size() && output[pos] != 0) ++pos;
    if (pos == output.size()) return true;

    for (int i{n}; i >= 2; --i) {
      if (exists[i]) continue;
      if (pos + i >= output.size()) return false;
      if (output[pos + i] != 0) continue;

      exists[i] = true;
      output[pos] = i;
      output[pos + i] = i;

      if (construct(n, exists, output, pos + 1)) return true;

      exists[i] = false;
      output[pos] = 0;
      output[pos + i] = 0;
    }

    if (!exists[1]) {
      exists[1] = true;
      output[pos] = 1;

      if (construct(n, exists, output, pos + 1)) return true;

      exists[1] = false;
      output[pos] = 0;
    }

    return false;
  }
};
