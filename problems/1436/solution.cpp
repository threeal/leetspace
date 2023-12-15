#include <set>
#include <string>
#include <vector>

class Solution {
 public:
  std::string destCity(std::vector<std::vector<std::string>>& paths) {
    std::set<std::string> starts;
    std::set<std::string> ends;

    for (const auto& path : paths) {
      if (!starts.contains(path[0])) {
        starts.insert(path[0]);
        if (ends.contains(path[0])) {
          ends.erase(path[0]);
        }
      }

      if (!starts.contains(path[1]) && !ends.contains(path[1])) {
        ends.insert(path[1]);
      }
    }

    return *ends.begin();
  }
};
