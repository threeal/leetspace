#include <queue>
#include <vector>

class Solution {
 public:
  bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
    std::queue<int> queue{};
    queue.push(0);

    std::vector<bool> visited(rooms.size(), false);
    visited[0] = true;

    std::size_t unvisited{rooms.size() - 1};
    while (!queue.empty()) {
      const int room{queue.front()};
      queue.pop();

      for (const int key : rooms[room]) {
        if (!visited[key]) {
          queue.push(key);
          visited[key] = true;
          --unvisited;
        }
      }
    }

    return unvisited == 0;
  }
};
