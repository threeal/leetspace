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
      schedules.begin(), schedules.end(), start,
      [](const Schedule& schedule, int val) {
        return schedule.start < val;
      });

    if (it == schedules.end()) {
      schedules.insert(it, {.start=start, .end=end});
      return true;
    }

    return start == end;
  }
};
