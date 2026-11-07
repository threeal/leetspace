#include <cmath>

class Solution {
 public:
  double angleClock(int hour, int minutes) {
    const double h = hour, m = minutes;
    const double angle{std::abs((h + m / 60.0) / 12.0 - m / 60.0)};
    return (angle < 0.5 ? angle : 1.0 - angle) * 360.0;
  }
};
