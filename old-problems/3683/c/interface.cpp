#include <cstring>
#include <vector>

extern "C" {
int earliestTime(int** tasks, int tasksSize, int* tasksColSize);
}

int solution_c(std::vector<std::vector<int>> tasks) {
  std::vector<int*> tasksDatas(tasks.size());
  std::vector<int> tasksSizes(tasks.size());
  for (std::size_t i{0}; i < tasks.size(); ++i) {
    tasksDatas[i] = tasks[i].data();
    tasksSizes[i] = tasks[i].size();
  }

  return earliestTime(tasksDatas.data(), tasks.size(), tasksSizes.data());
}
