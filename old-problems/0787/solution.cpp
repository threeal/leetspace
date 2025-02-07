#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <vector>

class Solution {
 public:
  int findCheapestPrice(
      int n, std::vector<std::vector<int>>& flights, int src, int dst, int k) {
    std::vector<std::list<std::tuple<int, int>>> nextCities(n);
    for (const auto& flight : flights) {
      nextCities[flight[0]].push_back({flight[1], flight[2]});
    }

    std::vector<int> distanceToCities(n, std::numeric_limits<int>::max());

    std::queue<std::tuple<int, int>> queue{};
    queue.push({src, 0});

    while (!queue.empty() && k >= 0) {
      for (std::size_t n{queue.size()}; n > 0; --n) {
        const auto [city, cost] = queue.front();
        queue.pop();

        for (const auto& [nextCity, nextCost] : nextCities[city]) {
          if (cost + nextCost >= distanceToCities[nextCity]) continue;
          distanceToCities[nextCity] = cost + nextCost;
          queue.push({nextCity, cost + nextCost});
        }
      }
      --k;
    }

    return distanceToCities[dst] != std::numeric_limits<int>::max()
        ? distanceToCities[dst]
        : -1;
  }
};
