#include <vector>

class MyHashSet {
 private:
  std::vector<bool> exists{};
  int existsSize{};

 public:
  MyHashSet() : exists{}, existsSize{0} {}

  void add(int key) {
    if (key >= existsSize) exists.resize(existsSize = key + 1);
    exists[key] = true;
  }

  void remove(int key) {
    if (key < existsSize) exists[key] = false;
  }

  bool contains(int key) {
    return key < existsSize ? exists[key] : false;
  }
};
