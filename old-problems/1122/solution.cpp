#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
    std::vector<int> order(1001, -1);
    for (int i = arr2.size() - 1; i >= 0; --i) {
      order[arr2[i]] = i;
    }

    const auto orderData = order.data();
    std::sort(arr1.begin(), arr1.end(), [orderData](const int a, const int b) {
      if (orderData[a] < 0) {
        if (orderData[b] < 0) {
          return a < b;
        } else {
          return false;
        }
      } else {
        if (orderData[b] < 0) {
          return true;
        } else {
          return orderData[a] < orderData[b];
        }
      }
    });

    return arr1;
  }
};
