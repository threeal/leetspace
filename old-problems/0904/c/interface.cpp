#include <vector>

extern "C" {
int totalFruit(int* fruits, int fruitsSize);
}

int solution_c(std::vector<int> fruits) {
  return totalFruit(fruits.data(), fruits.size());
}
