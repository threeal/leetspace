#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> validateCoupons(
      std::vector<std::string>& code,
      std::vector<std::string>& businessLine,
      std::vector<bool>& isActive) {
    std::vector<std::size_t> indices(code.size());
    std::iota(indices.begin(), indices.end(), 0);

    std::size_t n{0};
    for (std::size_t i : indices) {
      if (isValid(code[i], businessLine[i], isActive[i])) {
        indices[n++] = i;
      }
    }
    indices.resize(n);

    std::sort(
        indices.begin(), indices.end(),
        [&code, &businessLine](std::size_t a, std::size_t b) {
          return businessLine[a][0] != businessLine[b][0]
              ? businessLine[a][0] < businessLine[b][0]
              : code[a] < code[b];
        });

    businessLine.resize(indices.size());
    for (std::size_t i{0}; i < indices.size(); ++i) {
      businessLine[i] = code[indices[i]];
    }

    return businessLine;
  }

 private:
  static bool isValid(
      const std::string& code, const std::string& businessLine, bool isActive) {
    if (code.empty() || businessLine.empty() || !isActive) return false;

    switch (businessLine[0]) {
      case 'e':
        if (businessLine != "electronics") return false;
        break;

      case 'g':
        if (businessLine != "grocery") return false;
        break;

      case 'p':
        if (businessLine != "pharmacy") return false;
        break;

      case 'r':
        if (businessLine != "restaurant") return false;
        break;

      default:
        return false;
    }

    for (char c : code) {
      if (c == '_') continue;
      if (c >= 'a' && c <= 'z') continue;
      if (c >= 'A' && c <= 'Z') continue;
      if (c >= '0' && c <= '9') continue;
      return false;
    }

    return true;
  }
};
