#include <limits>
#include <vector>

class Solution {
 public:
  int distributeCookies(std::vector<int>& cookies, int k) {
    std::vector<int> children(k, 0);
    return search(cookies, 0, children);
  }

 private:
  int search(const std::vector<int>& cookies, std::size_t i, std::vector<int>& children) {
    if (i == cookies.size()) {
      int maxChild{0};
      for (const int child : children) {
        if (child > maxChild) maxChild = child;
      }
      return maxChild;
    }

    int minMaxChild{std::numeric_limits<int>::max()};
    for (int& child : children) {
      child += cookies[i];
      const int maxChild{search(cookies, i + 1, children)};
      if (maxChild < minMaxChild) minMaxChild = maxChild;
      child -= cookies[i];
    }

    return minMaxChild;
  }
};
