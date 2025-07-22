#include <cstring>
#include <string>
#include <vector>

extern "C" {
int* diStringMatch(char* s, int* returnSize);
}

std::vector<int> solution_c(std::string s) {
  int returnSize{};
  int* returnData{diStringMatch(s.data(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
