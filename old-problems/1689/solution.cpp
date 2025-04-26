#include <string>

class Solution {
 public:
  int minPartitions(std::string n) {
    char largest{'0'};
    for (const char c : n) {
      if (c > largest) largest = c;
    }
    return largest - '0';
  }
};
