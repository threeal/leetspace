#include <algorithm>
#include <queue>
#include <vector>

class Solution {
 public:
  int maxEvents(std::vector<std::vector<int>>& events) {
    std::sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
      return a[0] < b[0];
    });

    int count{0};
    int day{0};
    auto eventsIt = events.begin();
    std::priority_queue<int, std::vector<int>, std::greater<int>> eventEnds{};

    while (eventsIt != events.end() || !eventEnds.empty()) {
      if (eventEnds.empty() && day < (*eventsIt)[0]) {
        day = (*eventsIt)[0];
      }

      while (eventsIt != events.end() && (*eventsIt)[0] == day) {
        eventEnds.push((*eventsIt)[1]);
        ++eventsIt;
      }

      eventEnds.pop();
      ++count;
      ++day;

      while (!eventEnds.empty() && eventEnds.top() < day) {
        eventEnds.pop();
      }
    }

    return count;
  }
};
