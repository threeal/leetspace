#include <vector>

extern "C" {
int maximumGroups(int* grades, int gradesSize);
}

int solution_c(std::vector<int> grades) {
  return maximumGroups(grades.data(), grades.size());
}
