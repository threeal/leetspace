#include <string>

class Solution {
 public:
  long long numberOfPowerfulInt(
      long long start, long long finish, int limit, std::string s) {
    return start + finish + limit + s.size();
  }
};
