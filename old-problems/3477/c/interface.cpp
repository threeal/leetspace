#include <cstring>
#include <vector>

extern "C" {
int numOfUnplacedFruits(
    int* fruits, int fruitsSize, int* baskets, int basketsSize);
}

int solution_c(std::vector<int> fruits, std::vector<int> baskets) {
  return numOfUnplacedFruits(
      fruits.data(), fruits.size(), baskets.data(), baskets.size());
}
