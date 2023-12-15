// A destination city is defined as an end city that is not a start city.

#include <string>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::string destCity(std::vector<std::vector<std::string>>& paths) {
    // Store each start and end city from a path into sets.
    std::unordered_set<std::string> starts;
    std::unordered_set<std::string> ends;
    for (const auto& path : paths) {
      starts.insert(path[0]);
      ends.insert(path[1]);
    }

    // Find an end city that is not a start city.
    for (const auto& end : ends) {
      if (!starts.contains(end)) return end;
    }

    return "";
  }
};
