#include <tuple>
#include <unordered_set>
#include <vector>

struct TupleHash {
  std::size_t operator()(const std::tuple<int, int>& pos) const {
    return ((long long)std::get<0>(pos) << 32) ^ std::get<1>(pos);
  }
};

class Solution {
 public:
  int robotSim(
      std::vector<int>& commands, std::vector<std::vector<int>>& obstacles) {
    std::unordered_set<std::tuple<int, int>, TupleHash> hasObstacles{};

    std::unordered_map<int, std::vector<int>> xObstacles{};
    std::unordered_map<int, std::vector<int>> yObstacles{};

    for (const auto& obstacle : obstacles) {
      hasObstacles.insert({obstacle[0], obstacle[1]});
    }

    std::tuple<int, int> pos{0, 0};
    int dir{0};

    int maxDistance{0};
    for (const auto command : commands) {
      switch (command) {
        case -2:
          dir = (dir + 3) % 4;
          break;

        case -1:
          dir = (dir + 1) % 4;
          break;

        default:
          for (int i{0}; i < command; ++i) {
            switch (dir) {
              case 0:
                ++std::get<1>(pos);
                break;

              case 1:
                ++std::get<0>(pos);
                break;

              case 2:
                --std::get<1>(pos);
                break;

              case 3:
                --std::get<0>(pos);
                break;
            }

            if (hasObstacles.contains(pos)) {
              switch (dir) {
                case 0:
                  --std::get<1>(pos);
                  break;

                case 1:
                  --std::get<0>(pos);
                  break;

                case 2:
                  ++std::get<1>(pos);
                  break;

                case 3:
                  ++std::get<0>(pos);
                  break;
              }
              break;
            }

            const int distance{
                std::get<0>(pos) * std::get<0>(pos) +
                std::get<1>(pos) * std::get<1>(pos)};

            if (distance > maxDistance) maxDistance = distance;
          }
      }
    }

    return maxDistance;
  }
};
