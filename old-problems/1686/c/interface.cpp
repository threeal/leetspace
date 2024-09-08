#include <vector>

extern "C" {
int stoneGameVI(
    int* aliceValues, int aliceValuesSize, int* bobValues, int bobValuesSize);
}

int solution_c(std::vector<int> aliceValues, std::vector<int> bobValues) {
  return stoneGameVI(
      aliceValues.data(), aliceValues.size(),
      bobValues.data(), bobValues.size());
}
