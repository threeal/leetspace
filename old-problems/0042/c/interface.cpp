#include <vector>

extern "C" {
int trap(int* height, int heightSize);
}

int solution_c(std::vector<int> height) {
  return trap(height.data(), height.size());
}
