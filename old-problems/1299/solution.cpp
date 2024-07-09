#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<int> replaceElements(std::vector<int>& arr) {
    int max = arr.back();
    arr.back() = -1;

    for (int i = arr.size() - 2; i >= 0; --i) {
      if (arr[i] > max) {
        std::swap(arr[i], max);
      } else {
        arr[i] = max;
      }
    }

    return arr;
  }
};
