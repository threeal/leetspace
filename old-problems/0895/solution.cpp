#include <queue>
#include <tuple>
#include <unordered_map>

class FreqStack {
 private:
  std::unordered_map<int, int> freqs;
  std::priority_queue<std::tuple<int, int, int>> queue;
  int count;

 public:
  FreqStack() : freqs{}, queue{}, count{0} {}

  void push(int val) {
    queue.push({freqs[val]++, ++count, val});
  }

  int pop() {
    const int val{std::get<2>(queue.top())};
    queue.pop();

    --freqs[val];
    return val;
  }
};
