#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::string findCommonResponse(
      std::vector<std::vector<std::string>>& responses) {
    std::unordered_map<std::string_view, int> freqs{};
    for (const auto& responsesInDay : responses) {
      std::unordered_set<std::string_view> visited{};
      for (const auto& response : responsesInDay) {
        if (!visited.contains(response)) {
          visited.insert(response);
          ++freqs[response];
        }
      }
    }

    std::string_view candidate{};
    int candidateCount{0};

    for (const auto& [response, count] : freqs) {
      if (count > candidateCount ||
          (count == candidateCount && response < candidate)) {
        candidate = response;
        candidateCount = count;
      }
    }

    return std::string(candidate);
  }
};
