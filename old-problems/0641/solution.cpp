#include <vector>

class MyCircularDeque {
 private:
  std::vector<int> data;
  std::size_t left;
  std::size_t size;

 public:
  MyCircularDeque(int k) : data(k), left{0}, size{0} {}

  bool insertFront(int value) {
    if (size == data.size()) return false;

    if (left == 0) {
      left = data.size() - 1;
    } else {
      --left;
    }

    data[left] = value;
    ++size;

    return true;
  }

  bool insertLast(int value) {
    if (size == data.size()) return false;

    data[(left + size) % data.size()] = value;
    ++size;

    return true;
  }

  bool deleteFront() {
    if (size == 0) return false;
    if (left == data.size() - 1) {
      left = 0;
    } else {
      ++left;
    }
    --size;
    return true;
  }

  bool deleteLast() {
    if (size == 0) return false;
    --size;
    return true;
  }

  int getFront() {
    return size == 0 ? -1 : data[left];
  }

  int getRear() {
    if (size == 0) return -1;
    return size == 0 ? -1 : data[(left + size - 1) % data.size()];
  }

  bool isEmpty() {
    return size == 0;
  }

  bool isFull() {
    return size == data.size();
  }
};
