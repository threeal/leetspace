#include <algorithm>
#include <limits>
#include <vector>

class Solution {
 public:
  long long minimumTotalDistance(
      std::vector<int>& robot, std::vector<std::vector<int>>& factory) {
    std::sort(robot.begin(), robot.end());
    std::sort(factory.begin(), factory.end(), [](const auto& a, const auto& b) {
      return a[0] <= b[0];
    });

    std::vector<std::vector<long long>> cache(
        factory.size(), std::vector<long long>(robot.size(), -1));

    return recursiveMinimumTotalDistance(robot, factory, cache, 0, 0);
  }

 private:
  static long long recursiveMinimumTotalDistance(
      const std::vector<int>& robot,
      const std::vector<std::vector<int>>& factory,
      std::vector<std::vector<long long>>& cache,
      std::size_t robotIdx, std::size_t factoryIdx) {
    if (factoryIdx == factory.size()) return robotIdx == robot.size() ? 0 : -1;
    if (robotIdx == robot.size()) return 0;

    if (cache[factoryIdx][robotIdx] < 0) {
      auto minDistance = recursiveMinimumTotalDistance(
          robot, factory, cache, robotIdx, factoryIdx + 1);

      long long distance{0};
      for (int i{0}; i < factory[factoryIdx][1]; ++i) {
        if (robotIdx + i == robot.size()) break;
        distance += std::abs(factory[factoryIdx][0] - robot[robotIdx + i]);
        const auto restDistance = recursiveMinimumTotalDistance(
            robot, factory, cache, robotIdx + i + 1, factoryIdx + 1);
        if (restDistance < 0) continue;
        if (minDistance < 0 || distance + restDistance < minDistance) {
          minDistance = distance + restDistance;
        }
      }

      cache[factoryIdx][robotIdx] = minDistance;
    }

    return cache[factoryIdx][robotIdx];
  }
};
