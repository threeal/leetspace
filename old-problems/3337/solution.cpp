#include <array>
#include <string>
#include <vector>

class Solution {
 public:
  int lengthAfterTransformations(std::string s, int t, std::vector<int>& nums) {
    std::array<std::array<long long, 26>, 26> base{};
    for (int i{0}; i < 26; ++i) {
      for (int n{nums[i]}; n > 0; --n) {
        base[(i + n) % 26][i] = 1;
      }
    }

    std::array<std::array<long long, 26>, 26> transform{base};

    --t;
    while (t > 0) {
      if (t % 2 == 1) {
        const std::array<std::array<long long, 26>, 26> temp{transform};
        for (int i{0}; i < 26; ++i) {
          for (int j{0}; j < 26; ++j) {
            long long val{0};
            for (int k{0}; k < 26; ++k) {
              val = (val + temp[i][k] * base[k][j]) % 1000000007;
            }
            transform[i][j] = val;
          }
        }
      }

      const std::array<std::array<long long, 26>, 26> temp{base};
      for (int i{0}; i < 26; ++i) {
        for (int j{0}; j < 26; ++j) {
          int val{0};
          for (int k{0}; k < 26; ++k) {
            val = (val + temp[i][k] * temp[k][j]) % 1000000007;
          }
          base[i][j] = val;
        }
      }

      t /= 2;
    }

    std::array<int, 26> freqs{};
    for (const char c : s) ++freqs[c - 'a'];

    int count{0};
    for (int i{0}; i < 26; ++i) {
      for (int j{0}; j < 26; ++j) {
        count = (count + freqs[j] * transform[i][j]) % 1000000007;
      }
    }

    return count;
  }
};
