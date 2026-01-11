#include <sstream>
#include <string>

class Solution {
 public:
  std::string complexNumberMultiply(std::string num1, std::string num2) {
    std::size_t i{0};
    const int real1{parseNumber(num1, i, '+')};
    const int imagine1{parseNumber(num1, ++i, 'i')};

    i = 0;
    const int real2{parseNumber(num2, i, '+')};
    const int imagine2{parseNumber(num2, ++i, 'i')};

    const int real{real1 * real2 - imagine1 * imagine2};
    const int imagine{real1 * imagine2 + real2 * imagine1};

    std::stringstream ss{};
    ss << real << '+' << imagine << 'i';

    return ss.str();
  }

 private:
  static int parseNumber(const std::string& s, std::size_t& i, char c) {
    bool isNeg{false};
    if (s[i] == '-') {
      isNeg = true;
      ++i;
    }

    int num{0};
    while (s[i] != c) {
      num = num * 10 + s[i] - '0';
      ++i;
    }

    return isNeg ? -num : num;
  }
};
