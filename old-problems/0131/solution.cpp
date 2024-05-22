#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<std::string>> partition(std::string s) {
    return partition(s.data(), s.size());
  }

  std::vector<std::vector<std::string>> partition(const std::string& s, int n) {
    std::vector<std::vector<std::string>> output;

    for (int i{n - 1}; i >= 0; --i) {
      if (isPalindrome(s.data(), i, n - 1)) {
        if (i == 0) {
          output.push_back({s.substr(i, n - i)});
        } else {
          auto parts{partition(s, i)};
          if (!parts.empty()) {
            const auto substr{s.substr(i, n - i)};
            for (auto& part : parts) {
              part.push_back(substr);
            }
            output.insert(output.end(), parts.begin(), parts.end());
          }
        }
      }
    }

    return output;
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
