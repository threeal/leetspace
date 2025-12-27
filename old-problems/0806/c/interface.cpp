#include <cstring>
#include <vector>

extern "C" {
int* numberOfLines(int* widths, int widthsSize, char* s, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> widths, std::string s) {
  int returnSize{};
  int* returnData{
      numberOfLines(widths.data(), widths.size(), s.data(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
