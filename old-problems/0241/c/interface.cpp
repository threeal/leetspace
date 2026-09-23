#include <cstring>
#include <string>
#include <vector>

extern "C" {
int* diffWaysToCompute(char* expression, int* returnSize);
}

std::vector<int> solution_c(std::string expression) {
  int returnSize;
  const auto returnData = diffWaysToCompute(expression.data(), &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, sizeof(int) * returnSize);

  return output;
}
