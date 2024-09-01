#include <cstring>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> construct2DArray(
      std::vector<int>& original, int m, int n) {
    if (original.size() != static_cast<std::size_t>(m * n)) return {};
    std::vector<std::vector<int>> output(m, std::vector<int>(n));
    for (int i{m - 1}; i >= 0; --i) {
      std::memcpy(output[i].data(), original.data() + i * n, n * sizeof(int));
    }
    return output;
  }
};
