#include <vector>

class Solution {
 public:
  int idealArrays(int n, int maxValue) {
    std::vector<std::vector<int>> cache(maxValue + 1, std::vector(n, -1));
    for (int i{1}; i <= maxValue; ++i) cache[i][0] = 1;

    int total{0};
    for (int value{1}; value <= maxValue; ++value) {
      total = (total + countIdealArrays(cache, n - 1, value, maxValue)) %
        1000000007;
    }

    return total;
  }

 private:
  static int countIdealArrays(
      std::vector<std::vector<int>>& cache, int n, int value, int maxValue) {
    if (cache[value][n] == -1) {
      int total{0};
      for (int nextValue{value}; nextValue <= maxValue; nextValue += value) {
        total = (total + countIdealArrays(cache, n - 1, nextValue, maxValue)) %
          1000000007;
      }
      cache[value][n] = total;
    }

    return cache[value][n];
  }
};
