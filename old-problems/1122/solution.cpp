#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
    std::unordered_map<int, int> order{};
    for (int i = arr2.size() - 1; i >= 0; --i) {
      order.emplace(arr2[i], i);
    }

    std::sort(arr1.begin(), arr1.end(), [&order](const int a, const int b) {
      const auto ai = order.find(a);
      const auto bi = order.find(b);
      if (ai == order.end()) {
        if (bi == order.end()) {
          return a < b;
        } else {
          return false;
        }
      } else {
        if (bi == order.end()) {
          return true;
        } else {
          return ai->second < bi->second;
        }
      }
    });

    return arr1;
  }
};
