#include <vector>

extern "C" {
int removeBoxes(int* boxes, int boxesSize);
}

int solution_c(std::vector<int> boxes) {
  return removeBoxes(boxes.data(), boxes.size());
}
