#include <string>
#include <vector>

extern "C" {
char** fizzBuzz(int n, int* returnSize);
}

std::vector<std::string> solution_c(int n) {
  int returnSize{};
  const auto returnData = fizzBuzz(n, &returnSize);

  std::vector<std::string> output(returnSize);
  for (int i = returnSize - 1; i >= 0; --i) {
    output[i] = returnData[i];
  }

  return output;
}
