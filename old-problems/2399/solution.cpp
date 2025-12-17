#include <string>
#include <vector>

class Solution {
 public:
  bool checkDistances(std::string s, std::vector<int>& distance) {
    return s.empty() && distance.empty();
  }
};
