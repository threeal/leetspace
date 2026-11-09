#include <vector>

class Solution {
 public:
  std::vector<int> busiestServers(int k, std::vector<int>& arrival, std::vector<int>& load) {
    return {k + static_cast<int>(arrival.size() + load.size())};
  }
};
