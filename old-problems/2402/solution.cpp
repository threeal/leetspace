#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>

class Solution {
 public:
  int mostBooked(int n, std::vector<std::vector<int>>& meetings) {
    std::sort(meetings.begin(), meetings.end());

    std::priority_queue<int> roomsAvailable{};
    for (int i{0}; i < n; ++i) roomsAvailable.push(-i);

    std::priority_queue<std::tuple<long long, int>> roomsUsed{};
    std::vector<int> roomsCount(n, 0);

    for (const auto& meeting : meetings) {
      while (!roomsUsed.empty() && -std::get<0>(roomsUsed.top()) <= meeting[0]) {
        roomsAvailable.push(std::get<1>(roomsUsed.top()));
        roomsUsed.pop();
      }

      if (roomsAvailable.empty()) {
        const auto [negEndTime, negid] = roomsUsed.top();
        roomsUsed.pop();

        ++roomsCount[-negid];
        roomsUsed.push({negEndTime - meeting[1] + meeting[0], negid});
      } else {
        ++roomsCount[-roomsAvailable.top()];
        roomsUsed.push({-meeting[1], roomsAvailable.top()});
        roomsAvailable.pop();
      }
    }

    int room{0}, roomCount{roomsCount[0]};
    for (int i{1}; i < n; ++i) {
      if (roomsCount[i] > roomCount) {
        room = i;
        roomCount = roomsCount[i];
      }
    }

    return room;
  }
};
