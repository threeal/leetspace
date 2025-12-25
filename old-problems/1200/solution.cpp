#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());

    int minDiff{arr[1] - arr[0]};
    std::vector<std::vector<int>> output{{arr[0], arr[1]}};

    for (std::size_t i{2}; i < arr.size(); ++i) {
      const int diff{arr[i] - arr[i - 1]};
      if (diff > minDiff) continue;
      if (diff < minDiff) {
        minDiff = diff;
        output.clear();
      }
      output.push_back({arr[i - 1], arr[i]});
    }

    return output;
  }
};
