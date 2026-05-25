#include <queue>
#include <string>

class Solution {
 public:
  bool canReach(std::string s, int minJump, int maxJump) {
    if (s.back() == '1') return false;

    std::queue<std::size_t> jumps{}, jumpLaters{};
    jumpLaters.push(0);

    for (std::size_t i{1}; i < s.size(); ++i) {
      while (!jumpLaters.empty() && jumpLaters.front() + minJump <= i) {
        jumps.push(jumpLaters.front());
        jumpLaters.pop();
      }

      while (!jumps.empty() && jumps.front() + maxJump < i) jumps.pop();

      if (jumps.empty()) {
        if (jumpLaters.empty()) return false;
      } else {
        if (s[i] == '0') jumpLaters.push(i);
      }
    }

    return !jumps.empty();
  }
};
