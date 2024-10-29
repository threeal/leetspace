#include <string>
#include <string_view>
#include <unordered_set>

class Solution {
 public:
  int maxUniqueSplit(std::string s) {
    std::unordered_set<std::string_view> uniques{};
    return maxUniqueSplitView(uniques, s);
  }

  int maxUniqueSplitView(
      std::unordered_set<std::string_view>& uniques,
      std::string_view view) {
    int max{-1};
    for (std::size_t n{1}; n < view.size(); ++n) {
      const auto subview = view.substr(0, n);
      if (!uniques.contains(subview)) {
        uniques.insert(subview);
        const int subMax = maxUniqueSplitView(uniques, view.substr(n));
        if (subMax >= 0 && subMax + 1 > max) max = subMax + 1;
        uniques.erase(subview);
      }
    }

    if (!uniques.contains(view) && max < 1) max = 1;
    return max;
  }
};
