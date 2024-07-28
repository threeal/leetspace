#include <string>
#include <unordered_map>

class Solution {
 public:
  int minimumOperationsToMakeKPeriodic(std::string word, int k) {
    std::unordered_map<std::string, int> frequencies{};
    for (int i = word.size() - k; i >= 0; i -= k) {
      ++frequencies[word.substr(i, k)];
    }

    int highestFrequency{0};
    for (const auto& [word, frequency] : frequencies) {
      if (frequency > highestFrequency) highestFrequency = frequency;
    }

    return word.size() / k - highestFrequency;
  }
};
