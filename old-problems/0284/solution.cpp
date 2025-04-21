#include <vector>

class PeekingIterator : public Iterator {
 public:
  PeekingIterator(const std::vector<int>& nums) : Iterator(nums) {}

  int peek() {
    return 0;
  }

  // int next() {
  // }

  // bool hasNext() const {
  // }
};
