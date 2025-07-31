#include <string>
#include <vector>

extern "C" {
char** stringSequence(char* target, int* returnSize);
}

std::vector<std::string> solution_c(std::string target) {
  int returnSize{};
  char** returnData{stringSequence(target.data(), &returnSize)};

  std::vector<std::string> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i] = returnData[i];
  }

  return output;
}
