#include <vector>

extern "C" {
int findMaximizedCapital(
    int k, int w, int* profits, int profitsSize, int* capital, int capitalSize);
}

int solution_c(
    int k, int w, std::vector<int> profits, std::vector<int> capital) {
  return findMaximizedCapital(
      k, w, profits.data(), profits.size(), capital.data(), capital.size());
}
