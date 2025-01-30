#include <vector>

class Solution {
 public:
  std::vector<bool> checkIfPrerequisite(
      int numCourses, std::vector<std::vector<int>>& prerequisites,
      std::vector<std::vector<int>>& queries) {
    std::vector<bool> isPrerequisite(numCourses * numCourses, false);

    for (const auto& prerequisite : prerequisites) {
      isPrerequisite[prerequisite[0] * numCourses + prerequisite[1]] = true;
    }

    std::vector<bool> isChecked(numCourses, false), output(queries.size());
    for (std::size_t i{0}; i < queries.size(); ++i) {
      if (!isChecked[queries[i][0]]) {
        check(queries[i][0], numCourses, isPrerequisite, isChecked);
      }
      output[i] = isPrerequisite[queries[i][0] * numCourses + queries[i][1]];
    }

    return output;
  }

 private:
  static void check(
      int i, int numCourses, std::vector<bool>& isPrerequisite,
      std::vector<bool>& isChecked) {
    isChecked[i] = true;
    for (int j{0}; j < numCourses; ++j) {
      if (!isPrerequisite[i * numCourses + j]) continue;
      if (!isChecked[j]) check(j, numCourses, isPrerequisite, isChecked);
      for (int k{0}; k < numCourses; ++k) {
        if (!isPrerequisite[j * numCourses + k]) continue;
        isPrerequisite[i * numCourses + k] = true;
      }
    }
  }
};
