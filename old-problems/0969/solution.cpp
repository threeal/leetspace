#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> pancakeSort(std::vector<int> arr) {
    std::vector<int> output{};
    for (int n = arr.size(); n > 0; --n) {
      int i{0};
      while (arr[i] != n) ++i;
      if (i + 1 != n) {
        if (i != 0) {
          std::reverse(arr.begin(), arr.begin() + i + 1);
          output.push_back(i + 1);
        }

        std::reverse(arr.begin(), arr.begin() + n);
        output.push_back(n);
      }
    }
    return output;
  }
};
