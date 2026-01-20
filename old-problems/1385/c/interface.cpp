#include <vector>

extern "C" {
int findTheDistanceValue(
    int* arr1, int arr1Size, int* arr2, int arr2Size, int d);
}

int solution_c(std::vector<int> arr1, std::vector<int> arr2, int d) {
  return findTheDistanceValue(
      arr1.data(), arr1.size(), arr2.data(), arr2.size(), d);
}
