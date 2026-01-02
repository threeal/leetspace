#include <vector>

class Solution {
 public:
  int getImportance(std::vector<Employee*> employees, int id) {
    return employees.size() + id;
  }
};
