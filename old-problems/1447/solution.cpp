#include <numeric>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> simplifiedFractions(int n) {
    std::vector<std::string> output{};
    output.reserve(n * (n - 1) / 2);

    std::string str(7, 0);
    for (int a{1}; a < n; ++a) {
      std::size_t ai{print(str, 0, a)};
      str[ai++] = '/';
      for (int b{a + 1}; b <= n; ++b) {
        if (std::gcd(a, b) == 1) {
          const std::size_t bi{print(str, ai, b)};
          output.push_back(str.substr(0, bi));
        }
      }
    }

    return output;
  }

 private:
  static std::size_t print(std::string& str, std::size_t i, int num) {
    if (num < 10) {
      str[i] = '0' + num;
      return i + 1;
    } else if (num < 100) {
      str[i] = '0' + num / 10;
      str[i + 1] = '0' + num % 10;
      return i + 2;
    } else {
      str[i] = '0' + num / 100;
      str[i + 1] = '0' + (num / 10) % 10;
      str[i + 2] = '0' + num % 10;
      return i + 3;
    }
  }
};
