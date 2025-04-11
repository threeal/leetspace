#include <algorithm>
#include <string>

class Solution {
 public:
  std::string multiply(std::string num1, std::string num2) {
    std::reverse(num1.begin(), num1.end());
    for (auto& c : num1) c -= '0';

    std::reverse(num2.begin(), num2.end());
    for (auto& c : num2) c -= '0';

    std::string output(num1.size() + num2.size(), 0);

    char carry{0};
    for (std::size_t i{0}; i < num1.size(); ++i) {
      for (std::size_t j{0}; j < num2.size(); ++j) {
        carry += output[i + j] + num1[i] * num2[j];
        output[i + j] = carry % 10;
        carry /= 10;
      }
      if (carry > 0) {
        output[i + num2.size()] += carry;
        carry = 0;
      }
    }

    while (!output.empty() && output.back() == 0) output.pop_back();
    if (output.empty()) return "0";

    std::reverse(output.begin(), output.end());
    for (auto& c : output) c += '0';

    return output;
  }
};
