#include <string>
#include <vector>

class Solution {
 public:
  long long minimumCost(
      std::string source, std::string target,
      std::vector<std::string>& original, std::vector<std::string>& changed,
      std::vector<int>& cost) {
    return source.size() + target.size() + original.size() +
        changed.size() + cost.size();
  }
};
