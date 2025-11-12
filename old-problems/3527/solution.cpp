#include <string>
#include <vector>

class Solution {
 public:
  std::string findCommonResponse(
      std::vector<std::vector<std::string>>& responses) {
    return responses.front().front();
  }
};
