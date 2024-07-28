#include <cstring>
#include <vector>

extern "C" {
int** sortTheStudents(
    int** score, int scoreSize, int* scoreColSize, int k,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(
    std::vector<std::vector<int>> score, int k) {
  std::vector<int*> scoreDatas(score.size());
  std::vector<int> scoreSizes(score.size());
  for (int i = score.size() - 1; i >= 0; --i) {
    scoreDatas[i] = score[i].data();
    scoreSizes[i] = score[i].size();
  }

  int returnSize{};
  int* returnColumnSizes{};

  const auto returnData = sortTheStudents(
      scoreDatas.data(), scoreDatas.size(), scoreSizes.data(), k,
      &returnSize, &returnColumnSizes);

  std::vector<std::vector<int>> output(returnSize);
  for (int i{returnSize - 1}; i >= 0; --i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return output;
}
