#include <limits>
#include <sstream>
#include <string>

class Solution {
 public:
  std::string minimizeResult(std::string expression) {
    int minOutLeft{0}, minLeft{0}, minRight{0}, minOutRight{0};
    int minRes{std::numeric_limits<int>::max()};

    int outLeft{0};
    auto c1 = expression.data();
    while (*c1 != '+') {
      int left{0};
      auto c2 = c1;
      while (*c2 != '+') {
        left = left * 10 + *c2 - '0';
        ++c2;
      }

      int right{0};
      auto c3 = c2 + 1;
      while (*c3 != 0) {
        right = right * 10 + *c3 - '0';

        int outRight{0};
        auto c4 = c3 + 1;
        while (*c4 != 0) {
          outRight = outRight * 10 + *c4 - '0';
          ++c4;
        }

        auto res = left + right;
        if (outLeft > 0) res *= outLeft;
        if (outRight > 0) res *= outRight;
        if (res < minRes) {
          minOutLeft = outLeft;
          minLeft = left;
          minRight = right;
          minOutRight = outRight;
          minRes = res;
        }

        ++c3;
      }

      outLeft = outLeft * 10 + *c1 - '0';
      ++c1;
    }

    std::stringstream ss;
    if (minOutLeft > 0) ss << minOutLeft;
    ss << "(" << minLeft << "+" << minRight << ")";
    if (minOutRight > 0) ss << minOutRight;

    return ss.str();
  }
};
