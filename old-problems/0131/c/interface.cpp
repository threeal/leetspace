#include <string>
#include <vector>

extern "C" {
char*** partition(char* s, int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<std::string>> solution_c(std::string s) {
  int returnSize{};
  int* returnColumnSizes{nullptr};
  char*** returnData{partition(s.data(), &returnSize, &returnColumnSizes)};

  std::vector<std::vector<std::string>> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i].resize(returnColumnSizes[i]);
    for (std::size_t j{0}; j < output[i].size(); ++j) {
      output[i][j] = returnData[i][j];
    }
  }

  return output;
}
