#include <vector>

extern "C" {
int leastInterval(char* tasks, int tasksSize, int n);
}

int solution_c(std::vector<char> tasks, int n) {
  return leastInterval(tasks.data(), tasks.size(), n);
}
