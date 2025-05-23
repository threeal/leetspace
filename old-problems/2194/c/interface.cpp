#include <string>
#include <vector>

extern "C" {
char** cellsInRange(char* s, int* returnSize);
}

std::vector<std::string> solution_c(std::string s) {
  int returnSize{};
  char** returnData{cellsInRange(s.data(), &returnSize)};

  std::vector<std::string> output(returnSize);
  for (int i{0}; i < returnSize; ++i) {
    output[i] = returnData[i];
  }

  return output;
}
