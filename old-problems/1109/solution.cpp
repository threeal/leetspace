#include <vector>

class Solution {
 public:
  std::vector<int> corpFlightBookings(
      std::vector<std::vector<int>>& bookings, int n) {
    std::vector<int> seats(n + 1, 0);

    for (const auto& booking : bookings) {
      seats[booking[0] - 1] += booking[2];
      seats[booking[1]] -= booking[2];
    }

    for (int i{1}; i < n; ++i) {
      seats[i] += seats[i - 1];
    }

    seats.pop_back();
    return seats;
  }
};
