#include <vector>

class Cashier {
 public:
  Cashier(
      int /*n*/, int /*discount*/,
      std::vector<int>& /*products*/, std::vector<int>& /*prices*/) {
  }

  double getBill(std::vector<int> /*product*/, std::vector<int> /*amount*/) {
    return 0.0;
  }
};
