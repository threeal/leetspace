#include <string>

class Solution {
 public:
  int numberOfRounds(std::string loginTime, std::string logoutTime) {
    return loginTime.size() - logoutTime.size();
  }
};
