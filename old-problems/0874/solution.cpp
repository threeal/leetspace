#include <algorithm>
#include <unordered_map>
#include <vector>

enum class Direction {
  North,
  East,
  South,
  West,
};

class Solution {
 public:
  int robotSim(
      std::vector<int>& commands, std::vector<std::vector<int>>& obstacles) {
    std::unordered_map<int, std::vector<int>> xObstacles{};
    std::unordered_map<int, std::vector<int>> yObstacles{};

    for (const auto& obstacle : obstacles) {
      xObstacles[obstacle[0]].push_back(obstacle[1]);
      yObstacles[obstacle[1]].push_back(obstacle[0]);
    }

    for (auto& it : xObstacles) std::sort(it.second.begin(), it.second.end());
    for (auto& it : yObstacles) std::sort(it.second.begin(), it.second.end());

    int x{0}, y{0};
    Direction dir{Direction::North};

    int maxDistance{0};
    for (const auto command : commands) {
      if (command > 0) {
        switch (dir) {
          case Direction::North:
          case Direction::South: {
            const auto obstaclesIt = xObstacles.find(x);
            if (obstaclesIt == xObstacles.end()) {
              y += dir == Direction::North ? command : -command;
              break;
            }

            if (dir == Direction::North) {
              const auto obstacleIt = std::upper_bound(
                  obstaclesIt->second.begin(), obstaclesIt->second.end(), y);
              if (obstacleIt == obstaclesIt->second.end()) {
                y += command;
              } else {
                y = std::min(*obstacleIt - 1, y + command);
              }
            } else {
              const auto obstacleIt = std::upper_bound(
                  obstaclesIt->second.rbegin(), obstaclesIt->second.rend(), y,
                  std::greater<int>());
              if (obstacleIt == obstaclesIt->second.rend()) {
                y -= command;
              } else {
                y = std::max(*obstacleIt + 1, y - command);
              }
            }
            break;
          }

          case Direction::West:
          case Direction::East:
            const auto obstaclesIt = yObstacles.find(y);
            if (obstaclesIt == yObstacles.end()) {
              x += dir == Direction::West ? -command : command;
              break;
            }

            if (dir == Direction::West) {
              const auto obstacleIt = std::upper_bound(
                  obstaclesIt->second.rbegin(), obstaclesIt->second.rend(), x,
                  std::greater<int>());
              if (obstacleIt == obstaclesIt->second.rend()) {
                x -= command;
              } else {
                x = std::max(*obstacleIt + 1, x - command);
              }
            } else {
              const auto obstacleIt = std::upper_bound(
                  obstaclesIt->second.begin(), obstaclesIt->second.end(), x);
              if (obstacleIt == obstaclesIt->second.end()) {
                x += command;
              } else {
                x = std::min(*obstacleIt - 1, x + command);
              }
            }
            break;
        }

        maxDistance = std::max(maxDistance, x * x + y * y);
      } else {
        switch (dir) {
          case Direction::North:
            dir = command == -2 ? Direction::West : Direction::East;
            break;

          case Direction::East:
            dir = command == -2 ? Direction::North : Direction::South;
            break;

          case Direction::South:
            dir = command == -2 ? Direction::East : Direction::West;
            break;

          case Direction::West:
            dir = command == -2 ? Direction::South : Direction::North;
            break;
        }
      }
    }

    return maxDistance;
  }
};
