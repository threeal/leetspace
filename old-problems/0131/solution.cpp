#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<std::string>> partition(std::string s) {
    std::vector<std::vector<std::string>> output{};
    partition(output, s.data(), s.size());
    return output;
  }

  void partition(std::vector<std::vector<std::string>>& output, const std::string& s, int n) {
    for (int i{n - 1}; i >= 0; --i) {
      if (isPalindrome(s.data(), i, n - 1)) {
        if (i == 0) {
          output.push_back({s.substr(i, n - i)});
        } else {
          std::size_t j{output.size()};
          partition(output, s, i);
          while (j < output.size()) {
            output[j].push_back({s.substr(i, n - i)});
            ++j;
          }
        }
      }
    }
  }

  bool isPalindrome(const char* s, std::size_t left, std::size_t right) {
    while (left < right) {
      if (s[left] != s[right]) return false;
      ++left;
      --right;
    }
    return true;
  }
};
