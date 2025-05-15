#include <vector>

extern "C" {
int maxTaskAssign(
    int* tasks, int tasksSize, int* workers, int workersSize,
    int pills, int strength);
}

int solution_c(
    std::vector<int> tasks, std::vector<int> workers, int pills, int strength) {
  return maxTaskAssign(
      tasks.data(), tasks.size(), workers.data(), workers.size(),
      pills, strength);
}
