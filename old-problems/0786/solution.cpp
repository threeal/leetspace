#include <vector>

class Solution {
 public:
  std::vector<int> kthSmallestPrimeFraction(std::vector<int>& arr, int k) {
    const int n = arr.size();

    double left{0.0};
    double right{1.0};
    while (left <= right) {
      const double mid{left + (right - left) / 2.0};

      int total{0};
      int den{1};
      double maxFrac{0.0};
      int selectedNum{0};
      int selectedDen{0};
      for (int num = 0; num < n; ++num) {
        while (den < n && arr[num] >= arr[den] * mid) ++den;
        total += n - den;

        if (den < n && maxFrac < static_cast<double>(arr[num]) / static_cast<double>(arr[den])) {
          maxFrac = static_cast<double>(arr[num]) / static_cast<double>(arr[den]);
          selectedNum = num;
          selectedDen = den;
        }
      }

      if (total == k) return {arr[selectedNum], arr[selectedDen]};

      total > k ? right = mid : left = mid;
    }

    return {0, 0};
  }
};
