#include <queue>
#include <vector>

class SeatManager {
 private:
  int last;
  std::priority_queue<int, std::vector<int>, std::greater<int>> queue;

 public:
  SeatManager(int n) : last(0), queue{} {
    (void)n;
  }

  int reserve() {
    if (queue.empty()) return ++last;
    const int seat{queue.top()};
    queue.pop();
    return seat;
  }

  void unreserve(int seatNumber) {
    queue.push(seatNumber);
  }
};
