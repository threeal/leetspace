#include <vector>

extern "C" {
int minProcessingTime(
    int* processorTime, int processorTimeSize, int* tasks, int tasksSize);
}

int solution_c(std::vector<int> processorTime, std::vector<int> tasks) {
  return minProcessingTime(
      processorTime.data(), processorTime.size(), tasks.data(), tasks.size());
}
