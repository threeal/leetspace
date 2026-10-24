#include <string>

class Solution {
 private:
  static int countDays(const std::string& str) {
    static const int monthCounts[12]{
        0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    const int month{(str[0] - '0') * 10 + str[1] - '0'};
    const int date{(str[3] - '0') * 10 + str[4] - '0'};
    return monthCounts[month - 1] + date;
  }

 public:
  int countDaysTogether(
      std::string arriveAlice, std::string leaveAlice,
      std::string arriveBob, std::string leaveBob) {
    const int startA{countDays(arriveAlice)}, endA{countDays(leaveAlice)};
    const int startB{countDays(arriveBob)}, endB{countDays(leaveBob)};
    const int maxStart{startA >= startB ? startA : startB};
    const int minEnd{endA <= endB ? endA : endB};
    return maxStart <= minEnd ? minEnd - maxStart + 1 : 0;
  }
};
