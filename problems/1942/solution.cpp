#include <algorithm>
#include <queue>
#include <vector>

class Solution {
 public:
  int smallestChair(std::vector<std::vector<int>>& times, int targetFriend) {
    std::vector<int> arrivingFriends{};
    arrivingFriends.reserve(times.size());

    const int targetArrival{times[targetFriend][0]};
    for (std::size_t i{0}; i < times.size(); ++i) {
      if (times[i][0] < targetArrival) arrivingFriends.push_back(i);
    }

    std::sort(
        arrivingFriends.begin(), arrivingFriends.end(),
        [&times](const auto a, const auto b) {
          return times[a][0] < times[b][0];
        });

    std::vector<int> chairs(arrivingFriends.size() + 1, -1);

    const auto compare = [&times, &chairs](int a, int b) {
      return times[chairs[a]][1] > times[chairs[b]][1];
    };
    std::priority_queue<int, std::vector<int>, decltype(compare)>
        leavingChairs(compare);

    for (const auto arrivingFriend : arrivingFriends) {
      while (
          !leavingChairs.empty() &&
          times[chairs[leavingChairs.top()]][1] <= times[arrivingFriend][0]) {
        chairs[leavingChairs.top()] = -1;
        leavingChairs.pop();
      }

      for (std::size_t i{0}; i < chairs.size(); ++i) {
        if (chairs[i] < 0) {
          chairs[i] = arrivingFriend;
          leavingChairs.push(i);
          break;
        }
      }
    }

    while (!leavingChairs.empty() &&
           times[chairs[leavingChairs.top()]][1] <= times[targetFriend][0]) {
      chairs[leavingChairs.top()] = -1;
      leavingChairs.pop();
    }

    for (std::size_t i{0}; i < chairs.size(); ++i) {
      if (chairs[i] < 0) {
        return i;
      }
    }

    return chairs.size();
  }
};
