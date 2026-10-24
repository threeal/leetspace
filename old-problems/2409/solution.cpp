#include <string>

class Solution {
 public:
  int countDaysTogether(std::string arriveAlice, std::string leaveAlice, std::string arriveBob, std::string leaveBob) {
    return static_cast<int>(arriveAlice.size() + leaveAlice.size() + arriveBob.size() + leaveBob.size());
  }
};
