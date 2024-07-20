#include <string>

class Solution {
 public:
  bool isLongPressedName(std::string name, std::string typed) {
    char prevT = 0;
    auto t = typed.data();

    for (const auto c : name) {
      while (c != *t && prevT == *t) ++t;
      if (c != *t) return false;
      prevT = *t;
      ++t;
    }
    while (prevT == *t) ++t;

    return *t == 0;
  }
};
