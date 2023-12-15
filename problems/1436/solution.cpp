#include <string>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::string destCity(std::vector<std::vector<std::string>>& paths) {
    std::unordered_set<std::string> starts;
    std::unordered_set<std::string> ends;

    for (const auto& path : paths) {
      starts.insert(path[0]);
      ends.insert(path[1]);
    }

    for (const auto& end : ends) {
      if (!starts.contains(end)) return end;
    }

    return "";
  }
};
