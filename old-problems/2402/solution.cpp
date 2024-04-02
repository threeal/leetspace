#include <queue>
#include <vector>

struct Room {
  int id;
  int count;
  int timeAvailable;
};

bool operator<(const Room& lhs, const Room& rhs) {
  return lhs.timeAvailable > rhs.timeAvailable && lhs.id < rhs.id;
}

class Solution {
 public:
  int mostBooked(int n, std::vector<std::vector<int>>& meetings) {
    std::priority_queue<Room> rooms;
    for (int i = 0; i < n; ++i) {
      rooms.push({.id = i, .count = 0, .timeAvailable = 0});
    }

    for (const auto& meeting : meetings) {
      auto room = rooms.top();
      rooms.pop();

      ++room.count;
      room.timeAvailable = room.timeAvailable > meeting[0]
          ? room.timeAvailable + meeting[1] - meeting[0]
          : meeting[1];

      rooms.push(room);
    }

    int largestId = 0;
    int largestCount = 0;
    while (!rooms.empty()) {
      const auto& room = rooms.top();
      if (room.count >= largestCount) {
        largestId = room.count == largestCount ? std::min(largestId, room.id) : room.id;
        largestCount = room.count;
      }
      rooms.pop();
    }

    return largestId;
  }
};
