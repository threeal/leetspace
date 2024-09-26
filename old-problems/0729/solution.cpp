#include <algorithm>
#include <vector>

class MyCalendar {
 private:
  struct Schedule {
    int start;
    int end;
  };

  std::vector<Schedule> schedules;

 public:
  MyCalendar() : schedules{} {}

  bool book(int start, int end) {
    const auto it = std::lower_bound(
        schedules.begin(), schedules.end(), end,
        [](const Schedule& schedule, int val) {
          return schedule.end < val;
        });

    if (it == schedules.end()) {
      if (!schedules.empty() && schedules.back().end > start) return false;
      schedules.push_back({.start = start, .end = end});
      return true;
    }

    if (it->start < end) return false;
    if (it != schedules.begin()) {
      const auto prev = std::prev(it);
      if (prev->end > start) return false;
    }

    schedules.insert(it, {.start = start, .end = end});
    return true;
  }
};
