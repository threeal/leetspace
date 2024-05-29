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
  for (int i{returnSize - 1}; i >= 0; --i) {
    output[i].resize(returnColumnSizes[i]);
    for (int j{returnColumnSizes[i]}; j >= 0; --j) {
      const auto len{std::strlen(returnData[i][j])};
      output[i][j].resize(len);
      output[i][j].assign(returnData[i][j], len);
    }
  }

  return output;
}
