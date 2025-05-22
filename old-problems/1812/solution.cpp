#include <string>

class Solution {
 public:
  bool squareIsWhite(std::string coordinates) {
    return (coordinates[0] - 'a') % 2 != (coordinates[1] - '1') % 2;
  }
};
