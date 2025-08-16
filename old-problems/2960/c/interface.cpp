#include <vector>

extern "C" {
int countTestedDevices(int* batteryPercentages, int batteryPercentagesSize);
}

int solution_c(std::vector<int> batteryPercentages) {
  return countTestedDevices(
      batteryPercentages.data(), batteryPercentages.size());
}
