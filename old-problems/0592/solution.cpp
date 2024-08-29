#include <numeric>
#include <sstream>
#include <string>

class Solution {
 public:
  std::string fractionAddition(std::string expression) {
    bool isNegative{false};
    int prevNumerator{0};
    int prevDenominator{1};

    char* c{expression.data()};
    if (*c == '-') {
      isNegative = true;
      ++c;
    }

    while (*c != 0) {
      int numerator{0};
      while (*c >= '0') {
        numerator = numerator * 10 + (*c - '0');
        ++c;
      }
      ++c;

      int denominator{0};
      while (*c >= '0') {
        denominator = denominator * 10 + (*c - '0');
        ++c;
      }

      prevNumerator = isNegative
          ? prevNumerator * denominator - numerator * prevDenominator
          : prevNumerator * denominator + numerator * prevDenominator;
      prevDenominator *= denominator;

      const int gcd{std::gcd(prevNumerator, prevDenominator)};
      prevNumerator /= gcd;
      prevDenominator /= gcd;

      if (*c != 0) {
        isNegative = *c == '-';
        ++c;
      }
    }

    std::stringstream ss{};
    ss << prevNumerator << "/" << prevDenominator;
    return ss.str();
  }
};
