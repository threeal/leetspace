#include <vector>

class Solution {
 public:
  std::vector<int> decrypt(std::vector<int>& code, int k) {
    const int n = code.size();
    if (k > 0) {
      std::vector<int> output(n);

      int sum{0};
      for (int i{0}; i < k; ++i) sum += code[i];

      for (int l{0}, r{k}; r < n; ++l, ++r) {
        sum -= code[l];
        sum += code[r];
        output[l] = sum;
      }

      for (int l{n - k}, r{0}; l < n; ++l, ++r) {
        sum -= code[l];
        sum += code[r];
        output[l] = sum;
      }

      return output;
    } else if (k < 0) {
      std::vector<int> output(n);

      int sum{0};
      for (int i{n + k}; i < n; ++i) sum += code[i];

      for (int l{n + k - 1}, r{n - 1}; l >= 0; --l, --r) {
        sum += code[l];
        sum -= code[r];
        output[r] = sum;
      }

      for (int l{n - 1}, r{-k - 1}; r >= 0; --l, --r) {
        sum += code[l];
        sum -= code[r];
        output[r] = sum;
      }

      return output;
    }

    return std::vector<int>(n, 0);
  }
};
