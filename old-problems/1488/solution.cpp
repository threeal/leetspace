#include <numeric>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> avoidFlood(std::vector<int>& rains) {
    std::unordered_map<int, std::size_t> rainDays{};

    std::vector<std::size_t> drainDays(rains.size() + 1);
    std::iota(drainDays.begin(), drainDays.end(), 0);

    for (std::size_t i{0}; i < rains.size(); ++i) {
      if (rains[i] == 0) {
        rains[i] = 1;
      } else {
        drainDays[i] = findDrainDay(drainDays, i + 1);
        auto it = rainDays.find(rains[i]);
        if (it == rainDays.end()) {
          rainDays.emplace(rains[i], i);
        } else {
          const std::size_t day{findDrainDay(drainDays, it->second + 1)};
          if (day >= i) return {};
          rains[day] = rains[i];
          drainDays[day] = findDrainDay(drainDays, day + 1);
          it->second = i;
        }
        rains[i] = -1;
      }
    }

    return rains;
  }

 private:
  static std::size_t findDrainDay(
      std::vector<std::size_t>& drainDays, std::size_t day) {
    if (drainDays[day] == day) return day;
    return drainDays[day] = findDrainDay(drainDays, drainDays[day]);
  }
};
