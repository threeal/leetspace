#include <vector>

class Solution {
 public:
  int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
    return students.size() - sandwiches.size();
  }
};
