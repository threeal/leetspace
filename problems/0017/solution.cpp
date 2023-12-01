#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> letterCombinations(std::string digits) {
    const auto n = digits.size();
    if (n == 0) return {};

    // Calculate repeat for each digits.
    std::vector<size_t> repeats(n, 1);
    for (size_t i = 0; i < n; ++i) {
      repeats[i] = repeat_of(digits[i]);
      for (size_t j = 0; j < i; ++j) {
        repeats[j] *= repeats[i];
      }
    }

    // Pre-allocate list of string.
    std::vector<std::string> results(repeats[0]);
    for (auto& result : results) {
      result.resize(n);
    }

    for (size_t i = 0; i < n; ++i) {
      switch (digits[i]) {
        case '2':
          repeat_digit(results, "abc", repeats[i], i);
          break;

        case '3':
          repeat_digit(results, "def", repeats[i], i);
          break;

        case '4':
          repeat_digit(results, "ghi", repeats[i], i);
          break;

        case '5':
          repeat_digit(results, "jkl", repeats[i], i);
          break;

        case '6':
          repeat_digit(results, "mno", repeats[i], i);
          break;

        case '7':
          repeat_digit(results, "pqrs", repeats[i], i);
          break;

        case '8':
          repeat_digit(results, "tuv", repeats[i], i);
          break;

        case '9':
          repeat_digit(results, "wxyz", repeats[i], i);
          break;
      }
    }

    return results;
  }

  size_t repeat_of(char digit) {
    switch (digit) {
      case '7':
      case '9':
        return 4;
    }
    return 3;
  }

  void repeat_digit(std::vector<std::string>& results, const std::string& chars, size_t repeat, size_t i) {
    repeat /= chars.size();

    size_t j = 0;
    const auto n = results.size();
    while (j < n) {
      for (const auto c : chars) {
        for (size_t k = 0; k < repeat; ++k) {
          results[j + k][i] = c;
        }
        j += repeat;
      }
    }
  }
};
