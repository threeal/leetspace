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
    auto next = std::lower_bound(
        schedules.begin(), schedules.end(), end,
        [](const Schedule& schedule, int val) {
          return schedule.end < val;
        });

    if (next == schedules.end()) {
      if (!schedules.empty()) {
        if (start < schedules.back().end) return false;
        if (start == schedules.back().end) {
          schedules.back().end = end;
          return true;
        }
      }
      schedules.push_back({.start = start, .end = end});
      return true;
    }

    if (end > next->start) return false;
    if (next == schedules.begin()) {
      if (end == next->start) {
        next->start = start;
      } else {
        schedules.insert(schedules.begin(), {.start = start, .end = end});
      }
      return true;
    }

    auto prev = next - 1;
    if (prev->end > start) return false;

    if (prev->end == start) {
      if (next->start == end) {
        prev->end = next->end;
        schedules.erase(next);
      } else {
        prev->end = end;
      }
    } else {
      if (next->start == end) {
        next->start = start;
      } else {
        schedules.insert(next, {.start = start, .end = end});
      }
    }

    return true;
  }
};
