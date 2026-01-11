#include <stack>

class MyStack {
 private:
  std::stack<int> stack;

 public:
  MyStack() : stack{} {}

  void push(int x) {
    stack.push(x);
  }

  int pop() {
    const int top{stack.top()};
    stack.pop();
    return top;
  }

  int top() {
    return stack.top();
  }

  bool empty() {
    return stack.empty();
  }
};
