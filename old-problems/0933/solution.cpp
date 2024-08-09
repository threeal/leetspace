#include <queue>

class RecentCounter {
 private:
  std::queue<int> calls;

 public:
  RecentCounter() : calls{} {}

  int ping(int t) {
    calls.push(t);
    while (calls.front() < t - 3000) calls.pop();
    return calls.size();
  }
};
