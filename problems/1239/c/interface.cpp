#include <string>
#include <vector>

extern "C" {
int maxLength(char** arr, int arrSize);
}

int solution_c(std::vector<std::string> arr) {
  std::vector<char*> arrData(arr.size());
  for (std::size_t i = 0; i < arr.size(); ++i) {
    arrData[i] = arr[i].data();
  }

  return maxLength(arrData.data(), arrData.size());
}
