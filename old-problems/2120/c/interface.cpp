#include <cstring>
#include <string>
#include <vector>

extern "C" {
int* executeInstructions(
    int n, int* startPos, int startPosSize, char* s, int* returnSize);
}

std::vector<int> solution_c(int n, std::vector<int> startPos, std::string s) {
  int returnSize{};
  int* returnData{
      executeInstructions(
          n, startPos.data(), startPos.size(), s.data(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
