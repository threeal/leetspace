#include <vector>

class Solution {
 public:
  std::vector<int> memLeak(int memory1, int memory2) {
    int time{0};
    while (true) {
      ++time;
      if (memory1 >= memory2) {
        if (time > memory1) break;
        memory1 -= time;
      } else {
        if (time > memory2) break;
        memory2 -= time;
      }
    }
    return {time, memory1, memory2};
  }
};
