#include <cstring>
#include <vector>

extern "C" {
int* distributeCandies(int candies, int num_people, int* returnSize);
}

std::vector<int> solution_c(int candies, int num_people) {
  int returnSize{};
  int* returnData{distributeCandies(candies, num_people, &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
