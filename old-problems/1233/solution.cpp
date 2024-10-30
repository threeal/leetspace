#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
    std::sort(folder.begin(), folder.end());

    std::vector<std::string> output;
    output.push_back(folder.front());

    for (std::size_t i{1}; i < folder.size(); ++i) {
      const auto& prev = output.back();
      if (prev.size() < folder[i].size() && folder[i][prev.size()] == '/') {
        if (folder[i].compare(0, prev.size(), prev) == 0) continue;
      }

      output.push_back(folder[i]);
    }

    return output;
  }
};
