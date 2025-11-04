#include <string>
#include <unordered_map>

class Solution {
 public:
  std::string fractionToDecimal(int numerator, int denominator) {
    bool isNeg{false};
    long long llnumerator = numerator, lldenominator = denominator;
    if (llnumerator < 0) {
      llnumerator = -llnumerator;
      if (lldenominator < 0) {
        lldenominator = -lldenominator;
      } else {
        isNeg = true;
      }
    } else if (lldenominator < 0) {
      lldenominator = -lldenominator;
      isNeg = true;
    }

    const long long num{llnumerator / lldenominator};
    long long mod{llnumerator % lldenominator};
    if (mod == 0) return std::to_string(isNeg ? -num : num);

    std::string fraction{};
    std::unordered_map<long long, std::size_t> modPos{};

    for (std::size_t i{0}; mod > 0; ++i) {
      mod *= 10;

      auto it = modPos.find(mod);
      if (it != modPos.end()) {
        fraction.insert(fraction.begin() + it->second, '(');
        fraction.append(1, ')');
        break;
      } else {
        modPos.emplace(mod, i);
      }

      fraction.append(1, '0' + mod / lldenominator);
      mod -= mod / lldenominator * lldenominator;
    }

    const std::string numStr{std::to_string(num)};
    return (isNeg ? std::string("-") + numStr : numStr) + '.' + fraction;
  }
};
