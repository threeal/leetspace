#include <cstring>
#include <string>
#include <vector>

extern "C" {
char** findRelativeRanks(int* score, int scoreSize, int* returnSize);
}

std::vector<std::string> solution_c(std::vector<int> score) {
  int returnSize{};
  const auto returnData{findRelativeRanks(score.data(), score.size(), &returnSize)};

  std::vector<std::string> output(returnSize);
  for (int i{returnSize - 1}; i >= 0; --i) {
    const auto length{std::strlen(returnData[i])};
    output[i].resize(length);
    std::memcpy(output[i].data(), returnData[i], length * sizeof(char));
  }

  return output;
}
