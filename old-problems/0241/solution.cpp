#include <string>
#include <vector>

class Solution {
 public:
  std::vector<int> diffWaysToCompute(std::string expression) {
    std::vector<int> operands{};
    std::vector<char> operators{};

    int num{0};
    for (auto c = expression.data(); *c != 0; ++c) {
      if (*c >= '0') {
        num = num * 10 + *c - '0';
      } else {
        operands.push_back(num);
        operators.push_back(*c);
        num = 0;
      }
    }
    operands.push_back(num);

    std::vector<std::vector<std::vector<int>>> results(operands.size());
    for (std::size_t i{0}; i < results.size(); ++i) {
      results[i].resize(results.size() - i);
    }

    for (std::size_t i{0}; i < operands.size(); ++i) {
      results[0][i].push_back(operands[i]);
    }

    for (std::size_t n{1}; n < results.size(); ++n) {
      for (std::size_t i{0}; i < results[n].size(); ++i) {
        for (std::size_t j{0}; j < n; ++j) {
          for (const auto left : results[j][i]) {
            for (const auto right : results[n - j - 1][i + j + 1]) {
              int result{};
              switch (operators[i + j]) {
                case '+':
                  result = left + right;
                  break;
                case '-':
                  result = left - right;
                  break;
                case '*':
                  result = left * right;
                  break;
              }
              results[n][i].push_back(result);
            }
          }
        }
      }
    }

    return results.back().back();
  }
};
