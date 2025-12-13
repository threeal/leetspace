#include <cstring>
#include <string>
#include <vector>

extern "C" {
int* shortestToChar(char* s, char c, int* returnSize);
}

std::vector<int> solution_c(std::string s, char c) {
  int returnSize{};
  int* returnData{shortestToChar(s.data(), c, &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
