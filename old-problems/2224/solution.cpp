#include <string>

class Solution {
 public:
  int convertTime(std::string current, std::string correct) {
    const int seconds{
        (correct[0] * 600 + correct[1] * 60 + correct[3] * 10 + correct[4]) -
        (current[0] * 600 + current[1] * 60 + current[3] * 10 + current[4])};
    return seconds / 60 + seconds % 60 / 15 + seconds % 15 / 5 + seconds % 5;
  }
};
