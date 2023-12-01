#include <list>

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;

    std::list<int> list;
    std::size_t n = 0;
    while (x > 0) {
      list.push_back(x % 10);
      x = x / 10;
      ++n;
    }

    n = n / 2;
    auto a = list.begin();
    auto b = --list.end();
    for (std::size_t i = 0; i < n; ++i) {
      if (*a != *b) return false;
      ++a;
      --b;
    }
    return true;
  }
};
