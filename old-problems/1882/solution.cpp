#include <vector>

class Solution {
 public:
  std::vector<int> assignTasks(std::vector<int>& servers, std::vector<int>& tasks) {
    return {static_cast<int>(servers.size() + tasks.size())};
  }
};
