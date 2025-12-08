#include <cstring>
#include <string>
#include <vector>

extern "C" {
int* minOperations(char* boxes, int* returnSize);
}

std::vector<int> solution_c(std::string boxes) {
  int returnSize{};
  int* returnData{minOperations(boxes.data(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
