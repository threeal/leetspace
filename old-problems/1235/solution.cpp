#include <algorithm>
#include <functional>
#include <vector>

struct Job {
  int startTime;
  int endTime;
  int profit;
  int maxProfit = -1;
};

class Solution {
 public:
  int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit) {
    std::vector<Job> jobs(profit.size());
    for (std::size_t i = 0; i < jobs.size(); ++i) {
      jobs[i].startTime = startTime[i];
      jobs[i].endTime = endTime[i];
      jobs[i].profit = profit[i];
    }

    std::sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
      return a.startTime < b.startTime;
    });

    const std::function<int(std::vector<Job>::iterator)> fn = [&](std::vector<Job>::iterator it) {
      if (it == jobs.end()) return 0;
      if (it->maxProfit >= 0) return it->maxProfit;

      const int profitIfNotTake = fn(it + 1);

      const auto nextIfTake = std::lower_bound(it + 1, jobs.end(), it->endTime, [](const Job& job, int endTime) {
        return job.startTime < endTime;
      });

      const int profitIfTake = it->profit + fn(nextIfTake);

      return it->maxProfit = std::max(profitIfTake, profitIfNotTake);
    };

    return fn(jobs.begin());
  }
};
