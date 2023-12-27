#include <string>
#include <vector>

extern "C" {
int minCost(char* colors, int* neededTime, int neededTimeSize);
}

int solution_c(std::string colors, std::vector<int> neededTime) {
  return minCost(colors.data(), neededTime.data(), neededTime.size());
}
