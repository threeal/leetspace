#include <vector>

extern "C" {
int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize);
}

int solution_c(std::vector<int> students, std::vector<int> sandwiches) {
  return countStudents(students.data(), students.size(), sandwiches.data(), sandwiches.size());
}
