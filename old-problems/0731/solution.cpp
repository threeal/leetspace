#include <algorithm>
#include <vector>

class MyCalendarTwo {
 private:
  struct Booking {
    int date;
    int count;
  };

  std::vector<Booking> bookings;

 public:
  MyCalendarTwo() : bookings{} {}

  bool book(int start, int end) {
    auto it = std::lower_bound(
        bookings.begin(), bookings.end(), start,
        [](const auto& booking, int start) {
          return booking.date < start;
        });

    if (it == bookings.end()) {
      bookings.push_back({.date = start, .count = 1});
      bookings.push_back({.date = end, .count = 0});
      return true;
    }

    if (it->date > start) {
      if (it != bookings.begin() && std::prev(it)->count == 2) return false;
    }

    for (auto it2 = it; it2 != bookings.end() && it2->date < end; ++it2) {
      if (it2->count == 2) return false;
    }

    if (it->date > start) {
      const int count = it == bookings.begin() ? 1 : std::prev(it)->count + 1;
      it = bookings.insert(it, {.date = start, .count = count});
      ++it;
    }

    while (it != bookings.end() && it->date < end) {
      ++(it->count);
      ++it;
    }

    if (it == bookings.end()) {
      bookings.push_back({.date = end, .count = 0});
    } else if (it->date != end) {
      const int count = std::prev(it)->count - 1;
      bookings.insert(it, {.date = end, .count = count});
    }

    return true;
  }
};
