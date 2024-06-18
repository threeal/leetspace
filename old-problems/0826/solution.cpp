#include <algorithm>
#include <limits>
#include <vector>

struct Project {
  int difficulty;
  int profit;
};

class Solution {
 public:
  int maxProfitAssignment(
      std::vector<int>& difficulty,
      std::vector<int>& profit,
      std::vector<int>& worker) {
    std::vector<Project> projects(difficulty.size() + 1);
    for (int i = difficulty.size() - 1; i >= 0; --i) {
      projects[i].difficulty = difficulty[i];
      projects[i].profit = profit[i];
    }
    projects.back().difficulty = std::numeric_limits<int>::max();

    std::ranges::sort(projects, [](const auto& lhs, const auto& rhs) {
      return lhs.difficulty <= rhs.difficulty;
    });

    std::ranges::sort(worker);

    int profits{0};
    int maxProfit{0};
    auto projectIt = projects.begin();
    for (const auto workerDifficulty : worker) {
      while (projectIt->difficulty <= workerDifficulty) {
        if (projectIt->profit > maxProfit) maxProfit = projectIt->profit;
        ++projectIt;
      }
      profits += maxProfit;
    }

    return profits;
  }
};
