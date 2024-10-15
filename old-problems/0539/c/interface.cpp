#include <string>
#include <vector>

extern "C" {
int findMinDifference(char** timePoints, int timePointsSize);
}

int solution_c(std::vector<std::string> timePoints) {
  std::vector<char*> timePointsDatas(timePoints.size());
  for (std::size_t i{0}; i < timePoints.size(); ++i) {
    timePointsDatas[i] = timePoints[i].data();
  }

  return findMinDifference(timePointsDatas.data(), timePointsDatas.size());
}
