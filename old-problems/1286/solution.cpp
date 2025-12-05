#include <string>

class CombinationIterator {
 public:
  CombinationIterator(std::string characters, int combinationLength) {
    (void)characters;
    (void)combinationLength;
  }

  std::string next() {
    return "";
  }

  bool hasNext() {
    return false;
  }
};
