#include <string>
#include <vector>

extern "C" {
char** letterCasePermutation(char* s, int* returnSize);
}

std::vector<std::string> solution_c(std::string s) {
  int returnSize{};
  char** returnData{letterCasePermutation(s.data(), &returnSize)};

  std::vector<std::string> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i] = returnData[i];
  }

  return output;
}
