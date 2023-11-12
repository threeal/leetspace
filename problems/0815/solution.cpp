class Solution {
 public:
  int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    if (source == target) return 0;
    const int busCount = routes.size();

    unordered_map<int, unordered_set<int>> routesBuses;
    for (int bus = 0; bus < busCount; ++bus) {
      for (const auto route : routes[bus]) {
        routesBuses[route].insert(bus);
      }
    }

    vector<unordered_set<int>> busesConnections(busCount);
    for (const auto& [route, buses] : routesBuses) {
      for (const auto bus : buses) {
        for (const auto otherBus : buses) {
          busesConnections[bus].insert(otherBus);
        }
      }
    }

    const function<int(unordered_set<int>, int)> fn = [&](unordered_set<int> visitedBuses, int bus) -> int {
      if (routesBuses[target].contains(bus)) return 1;

      visitedBuses.insert(bus);
      int count = numeric_limits<int>::max();
      for (const auto bus : busesConnections[bus]) {
        if (visitedBuses.contains(bus)) continue;
        count = min(count, fn(visitedBuses, bus));
      }
      return count == numeric_limits<int>::max() ? count : 1 + count;
    };

    int count = numeric_limits<int>::max();
    for (const auto bus : routesBuses[source]) {
      count = min(count, fn({}, bus));
    }
    return count == numeric_limits<int>::max() ? -1 : count;
  }
};
