#include <utility>
#include <vector>

class Solution {
 public:
  int distanceBetweenBusStops(std::vector<int>& distance, int start, int destination) {
    if (start == destination) return 0;
    if (destination < start) std::swap(start, destination);

    int forwardDistance{0};
    for (int i{start}; i < destination; ++i) forwardDistance += distance[i];

    int backwardDistance{0};
    for (int i = distance.size() - 1; i >= destination; --i) backwardDistance += distance[i];
    for (int i{start - 1}; i >= 0; --i) backwardDistance += distance[i];

    return forwardDistance < backwardDistance ? forwardDistance : backwardDistance;
  }
};
