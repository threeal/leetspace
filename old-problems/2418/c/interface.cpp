#include <cstring>
#include <string>
#include <vector>

extern "C" {
char** sortPeople(
    char** names, int namesSize, int* heights, int heightsSize,
    int* returnSize);
}

std::vector<std::string> solution_c(
    std::vector<std::string> names, std::vector<int> heights) {
  std::vector<char*> namesDatas(names.size());
  for (int i = names.size() - 1; i >= 0; --i) {
    namesDatas[i] = names[i].data();
  }

  int returnSize;
  const auto returnData = sortPeople(
      namesDatas.data(), namesDatas.size(), heights.data(), heights.size(),
      &returnSize);

  std::vector<std::string> output(returnSize);
  for (int i = returnSize - 1; i >= 0; --i) {
    const auto length = std::strlen(returnData[i]);
    output[i].resize(length);
    std::memcpy(output[i].data(), returnData[i], length * sizeof(char));
  }

  return output;
}
