// The solution can be done as follows:
// - Create a hash table that maps buses to each route.
// - From the source route, get all buses.
// - If the target route contains any of the current buses, return the required number of buses.
// - Else, get all buses that are connected with the current buses and repeat the previous step.

class Solution {
 public:
  int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    // Bus is not required if the source and target routes are the same.
    if (source == target) return 0;

    // Create a hash table that maps buses to each route.
    const int busCount = routes.size();
    unordered_map<int, unordered_set<int>> routesBuses;
    for (int bus = 0; bus < busCount; ++bus) {
      for (const auto route : routes[bus]) {
        routesBuses[route].insert(bus);
      }
    }

    // Mark the source route as visited.
    unordered_set<int> visitedRoutes;
    visitedRoutes.insert(source);

    // Get all buses from the source route.
    list<int> busesToVisit;
    unordered_set<int> visitedBuses;
    for (const auto bus : routesBuses[source]) {
      busesToVisit.push_back(bus);
      visitedBuses.insert(bus);
    }

    // Repeat until there is no more bus to visit.
    int count = 1;
    while (!busesToVisit.empty()) {
      list<int> nextBusesToVisit;
      for (const auto busToVisit : busesToVisit) {
        // If the current bus has the target route, return the required number of buses to visit.
        if (routesBuses[target].contains(busToVisit)) return count;

        // Get the next bus to visit from the current bus.
        for (const auto route : routes[busToVisit]) {
          if (visitedRoutes.contains(route)) continue;
          visitedRoutes.insert(route);
          for (const auto bus : routesBuses[route]) {
            if (visitedBuses.contains(bus)) continue;
            nextBusesToVisit.push_back(bus);
            visitedBuses.insert(bus);
          }
        }
      }

      // Update the next buses to visit and update the bus counter.
      busesToVisit = nextBusesToVisit;
      ++count;
    }

    // Could not reach the target route from the source route.
    return -1;
  }
};
