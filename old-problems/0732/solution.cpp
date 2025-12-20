#include <map>

class MyCalendarThree {
 private:
  std::map<int, int> tree;
  int maxCount;

 public:
  MyCalendarThree() : tree{{-1, 0}}, maxCount{0} {}

  int book(int startTime, int endTime) {
    auto startIt = --tree.upper_bound(startTime);
    if (startIt->first != startTime) {
      startIt = tree.emplace(startTime, startIt->second).first;
    }

    auto endIt = --tree.upper_bound(endTime);
    if (endIt->first != endTime) {
      endIt = tree.emplace(endTime, endIt->second).first;
    }

    for (auto it = startIt; it != endIt; ++it) {
      ++it->second;
      if (it->second > maxCount) maxCount = it->second;
    }

    return maxCount;
  }
};
