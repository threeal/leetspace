#include <stack>

class MyQueue {
 private:
  std::stack<int> pushes;
  std::stack<int> pops;

 public:
  MyQueue() {}

  void push(int x) {
    pushes.push(x);
  }

  int pop() {
    const auto val = peek();
    pops.pop();
    return val;
  }

  int peek() {
    if (pops.empty()) {
      while (!pushes.empty()) {
        pops.push(pushes.top());
        pushes.pop();
      }
    }
    return pops.top();
  }

  bool empty() {
    return pops.empty() && pushes.empty();
  }
};
