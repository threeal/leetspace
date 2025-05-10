#include <vector>

extern "C" {
int numberOfEmployeesWhoMetTarget(int* hours, int hoursSize, int target);
}

int solution_c(std::vector<int> hours, int target) {
  return numberOfEmployeesWhoMetTarget(hours.data(), hours.size(), target);
}
