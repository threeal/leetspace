#include <algorithm>
#include <vector>

struct Project {
  int profit;
  int capital;
};

class Solution {
 public:
  int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
    std::vector<Project> projects(profits.size());
    for (int i = projects.size() - 1; i >= 0; --i) {
      projects[i].profit = profits[i];
      projects[i].capital = capital[i];
    }

    std::sort(projects.begin(), projects.end(), [](const auto& lhs, const auto& rhs) {
      return lhs.capital < lhs.capital || lhs.profit < rhs.profit;
    });
    auto projectsIt = projects.begin();

    std::vector<int> maxProfits{};
    maxProfits.reserve(projects.size());

    while (--k >= 0) {
      if (projectsIt != projects.end() && projectsIt->capital <= w) {
        do {
          maxProfits.push_back(projectsIt->profit);
          ++projectsIt;
        } while (projectsIt != projects.end() && projectsIt->capital <= w);

        std::sort(maxProfits.begin(), maxProfits.end());
      }

      if (maxProfits.empty()) return w;

      w += maxProfits.back();
      maxProfits.pop_back();
    }

    return w;
  }
};
