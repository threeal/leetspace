class MyCircularDeque {
 public:
  MyCircularDeque(int /*k*/) {}

  bool insertFront(int value) {
    return value == 0;
  }

  bool insertLast(int value) {
    return value == 0;
  }

  bool deleteFront() {
    return false;
  }

  bool deleteLast() {
    return false;
  }

  int getFront() {
    return 0;
  }

  int getRear() {
    return 0;
  }

  bool isEmpty() {
    return false;
  }

  bool isFull() {
    return false;
  }
};
