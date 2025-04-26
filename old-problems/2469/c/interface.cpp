#include <cstring>
#include <vector>

extern "C" {
double* convertTemperature(double celsius, int* returnSize);
}

std::vector<double> solution_c(double celsius) {
  int returnSize{};
  double* returnData{convertTemperature(celsius, &returnSize)};

  std::vector<double> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(double));

  return output;
}
