#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>

class Solution {
 public:
  int smallestChair(std::vector<std::vector<int>>& times, int targetFriend) {
    std::vector<std::tuple<int, int>> events{};
    events.reserve(times.size() * 2 - 2);

    const int targetArrival{times[targetFriend][0]};
    for (int i{0}; i < static_cast<int>(times.size()); ++i) {
      if (times[i][0] < targetArrival) {
        events.push_back({times[i][0], i});
        if (times[i][1] <= targetArrival) {
          events.push_back({times[i][1], ~i});
        }
      }
    }

    std::sort(
        events.begin(), events.end(),
        [](const auto a, const auto b) {
          return std::get<0>(a) == std::get<0>(b)
              ? std::get<1>(a) < 0
              : std::get<0>(a) < std::get<0>(b);
        });

    std::vector<int> chairs(times.size());

    std::priority_queue<int, std::vector<int>, std::greater<int>> available{};
    for (int i = times.size(); i >= 0; --i) available.push(i);

    for (const auto& [time, idx] : events) {
      if (idx >= 0) {
        chairs[idx] = available.top();
        available.pop();
      } else {
        available.push(chairs[~idx]);
      }
    }

    return available.top();
  }
};
