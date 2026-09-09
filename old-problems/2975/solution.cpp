#include <cstdlib>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int maximizeSquareArea(
      int m, int n, std::vector<int>& hFences, std::vector<int>& vFences) {
    std::unordered_set<int> widths{};

    widths.insert(m - 1);
    for (std::size_t i{0}; i < hFences.size(); ++i) {
      widths.insert(hFences[i] - 1);
      widths.insert(m - hFences[i]);

      for (std::size_t j{i + 1}; j < hFences.size(); ++j) {
        widths.insert(std::abs(hFences[i] - hFences[j]));
      }
    }

    int maxWidth{0};

    int width{n - 1};
    if (width > maxWidth && widths.contains(width)) maxWidth = width;

    for (std::size_t i{0}; i < vFences.size(); ++i) {
      width = vFences[i] - 1;
      if (width > maxWidth && widths.contains(width)) maxWidth = width;

      width = n - vFences[i];
      if (width > maxWidth && widths.contains(width)) maxWidth = width;

      for (std::size_t j{i + 1}; j < vFences.size(); ++j) {
        width = std::abs(vFences[i] - vFences[j]);
        if (width > maxWidth && widths.contains(width)) maxWidth = width;
      }
    }

    return maxWidth != 0
        ? static_cast<long long>(maxWidth) * maxWidth % 1000000007
        : -1;
  }
};
