#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> stringMatching(std::vector<std::string>& words) {
    std::sort(words.begin(), words.end(), [](const auto& a, const auto& b) {
      return a.size() < b.size();
    });

    std::vector<std::string> output{};
    for (auto it = words.begin(); it != words.end(); ++it) {
      for (auto otherIt = std::next(it); otherIt != words.end(); ++otherIt) {
        if (otherIt->find(*it) != std::string::npos) {
          output.push_back(*it);
          break;
        }
      }
    }

    return output;
  }
};
