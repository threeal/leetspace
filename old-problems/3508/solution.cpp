#include <vector>

class Router {
 public:
  Router(int memoryLimit) {
    (void)memoryLimit;
  }

  bool addPacket(int source, int destination, int timestamp) {
    return source == destination && timestamp == 0;
  }

  std::vector<int> forwardPacket() {
    return {};
  }

  int getCount(int destination, int startTime, int endTime) {
    return destination + startTime + endTime;
  }
};
