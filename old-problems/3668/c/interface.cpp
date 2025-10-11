
#include <cstring>
#include <vector>

extern "C" {
int* recoverOrder(
    int* order, int orderSize, int* friends, int friendsSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> order, std::vector<int> friends) {
  int returnSize{};
  int* returnData{
      recoverOrder(
          order.data(), order.size(),
          friends.data(), friends.size(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
