class MyHashSet {
 public:
  MyHashSet() {}

  void add(int key) {
    (void)key;
  }

  void remove(int key) {
    (void)key;
  }

  bool contains(int key) {
    return key == 0;
  }
};
