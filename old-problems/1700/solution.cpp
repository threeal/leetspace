#include <vector>

class Solution {
 public:
  int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
    int preferCircular{0};
    int preferSquare{0};
    for (const auto student : students) {
      student == 0 ? ++preferCircular : ++preferSquare;
    }

    for (const auto sandwich : sandwiches) {
      if (sandwich == 0) {
        if (--preferCircular < 0) return preferSquare;
      } else {
        if (--preferSquare < 0) return preferCircular;
      }
    }

    return 0;
  }
};
