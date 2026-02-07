#include <algorithm>
#include <string>

class Solution {
 public:
  std::string digitSum(std::string s, int k) {
    int n = s.size();
    while (n > k) {
      int l{0};
      for (int i{0}; i < n; i += k) {
        int num{0};
        const int kn{std::min(i + k, n)};
        for (int j{i}; j < kn; ++j) {
          num += s[j] - '0';
        }

        if (num == 0) {
          s[l++] = '0';
        } else {
          int exp{1};
          while (exp <= num) exp *= 10;
          while ((exp /= 10) != 0) s[l++] = '0' + (num / exp) % 10;
        }
      }
      n = l;
    }

    return s.substr(0, n);
  }
};
