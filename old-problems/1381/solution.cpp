#include <vector>

class CustomStack {
 private:
  std::vector<int> data;
  std::size_t size;

 public:
  CustomStack(int maxSize) : data(maxSize), size{0} {}

  void push(int x) {
    if (size == data.size()) return;
    data[size] = x;
    if (size > 0) data[size - 1] -= x;
    ++size;
  }

  int pop() {
    if (size == 0) return -1;
    --size;
    if (size > 0) data[size - 1] += data[size];
    return data[size];
  }

  void increment(int k, int val) {
    if (size == 0) return;
    if (k > static_cast<int>(size)) k = size;
    data[k - 1] += val;
  }
};
