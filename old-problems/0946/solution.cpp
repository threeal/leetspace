#include <vector>

class Solution {
 public:
  bool validateStackSequences(
      std::vector<int>& pushed, std::vector<int>& popped) {
    std::size_t l{1}, r{1}, i{0};
    while (true) {
      if (l == 0 || pushed[l - 1] != popped[i]) {
        if (r == pushed.size()) break;
        pushed[l++] = pushed[r++];
      } else {
        --l;
        ++i;
        if (i == popped.size()) break;
      }
    }
    return i == popped.size();
  }
};
