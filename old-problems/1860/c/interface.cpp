#include <cstring>
#include <vector>

extern "C" {
int* memLeak(int memory1, int memory2, int* returnSize);
}

std::vector<int> solution_c(int memory1, int memory2) {
  int returnSize{};
  int* returnData{memLeak(memory1, memory2, &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
