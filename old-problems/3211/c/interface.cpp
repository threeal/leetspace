#include <string>
#include <vector>

extern "C" {
char** validStrings(int n, int* returnSize);
}

std::vector<std::string> solution_c(int n) {
  int returnSize{};
  char** returnData{validStrings(n, &returnSize)};

  std::vector<std::string> output(returnSize);
  for (int i{0}; i < returnSize; ++i) output[i] = returnData[i];

  return output;
}
