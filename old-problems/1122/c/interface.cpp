#include <cstring>
#include <vector>

extern "C" {
int* relativeSortArray(
    int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> arr1, std::vector<int> arr2) {
  int returnSize{};
  const int* returnData{
      relativeSortArray(
          arr1.data(), arr1.size(), arr2.data(), arr2.size(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
