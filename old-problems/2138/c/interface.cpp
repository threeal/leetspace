#include <string>
#include <vector>

extern "C" {
char** divideString(char* s, int k, char fill, int* returnSize);
}

std::vector<std::string> solution_c(std::string s, int k, char fill) {
  int returnSize;
  char** returnData{divideString(s.data(), k, fill, &returnSize)};

  std::vector<std::string> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i] = returnData[i];
  }

  return output;
}
