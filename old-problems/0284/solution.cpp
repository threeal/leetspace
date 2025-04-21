#include <vector>

class PeekingIterator : public Iterator {
 private:
  bool hasPeeked;
  int peekedVal;

 public:
  PeekingIterator(const std::vector<int>& nums)
      : Iterator(nums), hasPeeked{false}, peekedVal{} {}

  int peek() {
    if (!hasPeeked) {
      peekedVal = Iterator::next();
      hasPeeked = true;
    }
    return peekedVal;
  }

  int next() {
    if (!hasPeeked) return Iterator::next();
    hasPeeked = false;
    return peekedVal;
  }

  bool hasNext() const {
    return hasPeeked || Iterator::hasNext();
  }
};
