#include <vector>

class Solution {
 public:
  std::vector<bool> checkIfPrerequisite(
      int numCourses, std::vector<std::vector<int>>& prerequisites,
      std::vector<std::vector<int>>& queries) {
    (void)numCourses;
    (void)prerequisites;
    return std::vector<bool>(queries.size(), false);
  }
};
