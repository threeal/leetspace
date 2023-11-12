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

    unordered_set<int> visitedRoutes;
    unordered_set<int> visitedBuses;
    unordered_set<int> busesToVisit = routesBuses[source];

    int count = 1;
    while (!busesToVisit.empty()) {
      for (const auto busToVisit : busesToVisit) {
        visitedBuses.insert(busToVisit);
      }

      unordered_set<int> nextBusesToVisit;
      for (const auto busToVisit : busesToVisit) {
        if (routesBuses[target].contains(busToVisit)) return count;
        for (const auto route : routes[busToVisit]) {
          if (visitedRoutes.contains(route)) continue;
          visitedRoutes.insert(route);
          for (const auto bus : routesBuses[route]) {
            if (visitedBuses.contains(bus)) continue;
            nextBusesToVisit.insert(bus);
          }
        }
      }

      busesToVisit = nextBusesToVisit;
      ++count;
    }

    return -1;
  }
};
