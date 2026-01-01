#include <cstdlib>
#include <string>
#include <vector>

extern "C" {
char** validateCoupons(
    char** code, int codeSize, char** businessLine, int businessLineSize,
    bool* isActive, int isActiveSize, int* returnSize);
}

std::vector<std::string> solution_c(
    std::vector<std::string> code, std::vector<std::string> businessLine,
    std::vector<bool> isActive) {
  std::vector<char*> codeDatas(code.size());
  for (std::size_t i{0}; i < code.size(); ++i) {
    codeDatas[i] = code[i].data();
  }

  std::vector<char*> businessLineDatas(businessLine.size());
  for (std::size_t i{0}; i < businessLine.size(); ++i) {
    businessLineDatas[i] = businessLine[i].data();
  }

  bool* isActiveDatas{
      static_cast<bool*>(malloc(isActive.size() * sizeof(bool)))};

  for (std::size_t i{0}; i < isActive.size(); ++i) {
    isActiveDatas[i] = isActive[i];
  }

  int returnSize{};
  char** returnData{
      validateCoupons(
          codeDatas.data(), code.size(), businessLineDatas.data(),
          businessLine.size(), isActiveDatas, isActive.size(), &returnSize)};

  std::vector<std::string> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i] = returnData[i];
  }

  free(isActiveDatas);

  return output;
}
