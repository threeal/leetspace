#include <unordered_map>
#include <vector>

class Solution {
 public:
  int getImportance(std::vector<Employee*> employees, int id) {
    std::unordered_map<int, Employee*> employeesMap{};
    for (Employee* employee : employees) {
      employeesMap.emplace(employee->id, employee);
    }

    return sumImportance(employeesMap, id);
  }

 private:
  static int sumImportance(
      std::unordered_map<int, Employee*>& employeesMap, int id) {
    Employee* employee = employeesMap[id];
    int sum{employee->importance};
    for (int subordinate : employee->subordinates) {
      sum += sumImportance(employeesMap, subordinate);
    }
    return sum;
  }
};
