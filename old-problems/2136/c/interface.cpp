#include <vector>

extern "C" {
int earliestFullBloom(
    int* plantTime, int plantTimeSize, int* growTime, int growTimeSize);
}

int solution_c(std::vector<int> plantTime, std::vector<int> growTime) {
  return earliestFullBloom(
      plantTime.data(), plantTime.size(), growTime.data(), growTime.size());
}
