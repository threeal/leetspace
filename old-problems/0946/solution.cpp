#include <vector>

class Solution {
 public:
  bool validateStackSequences(
      std::vector<int>& pushed, std::vector<int>& popped) {
    return pushed.empty() && popped.empty();
  }
};
