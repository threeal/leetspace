#include <cstring>
#include <vector>

extern "C" {
int* successfulPairs(
    int* spells, int spellsSize, int* potions, int potionsSize,
    long long success, int* returnSize);
}

std::vector<int> solution_c(
    std::vector<int> spells, std::vector<int> potions, long long success) {
  int returnSize{};
  int* returnData{
      successfulPairs(
          spells.data(), spells.size(), potions.data(), potions.size(),
          success, &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
