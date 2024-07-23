#include <string>
#include <string_view>

class Solution {
 public:
  std::string gcdOfStrings(std::string str1, std::string str2) {
    for (std::size_t n = std::min(str1.size(), str2.size()); n > 0; --n) {
      if (str1.size() % n != 0) continue;
      if (str2.size() % n != 0) continue;
      if (checkCommonDivisor(str1, str2, n)) {
        return str1.substr(0, n);
      }
    }
    return "";
  }

  bool checkCommonDivisor(
      std::string_view str1, std::string_view str2, std::size_t n) {
    for (int i = n - 1; i >= 0; --i) {
      if (str1[i] != str2[i]) return false;

      for (std::size_t j = i + n; j < str1.size(); j += n) {
        if (str1[j] != str1[i]) return false;
      }

      for (std::size_t j = i + n; j < str2.size(); j += n) {
        if (str2[j] != str2[i]) return false;
      }
    }

    return true;
  }
};
