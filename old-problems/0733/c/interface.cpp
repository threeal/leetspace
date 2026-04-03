#include <cstring>
#include <vector>

extern "C" {
int** floodFill(
    int** image, int imageSize, int* imageColSize, int sr, int sc, int color,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(
    std::vector<std::vector<int>> image, int sr, int sc, int color) {
  std::vector<int*> imageDatas(image.size());
  std::vector<int> imageSizes(image.size());
  for (std::size_t i{0}; i < image.size(); ++i) {
    imageDatas[i] = image[i].data();
    imageSizes[i] = image[i].size();
  }

  int returnSize{};
  int* returnColumnSizes{};
  int** returnData{
      floodFill(
          imageDatas.data(), image.size(), imageSizes.data(), sr, sc, color,
          &returnSize, &returnColumnSizes)};

  std::vector<std::vector<int>> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(output[i].data(), returnData[i], output[i].size() * sizeof(int));
  }

  return output;
}
