#include <vector>

extern "C" {
int minimumEffort(int** tasks, int tasksSize, int* tasksColSize);
}

int solution_c(std::vector<std::vector<int>> tasks) {
  std::vector<int*> tasksDatas(tasks.size());
  std::vector<int> taskSizes(tasks.size());
  for (std::size_t i{0}; i < tasks.size(); ++i) {
    tasksDatas[i] = tasks[i].data();
    taskSizes[i] = tasks[i].size();
  }

  return minimumEffort(tasksDatas.data(), tasks.size(), taskSizes.data());
}
