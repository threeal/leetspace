#include <sstream>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> summaryRanges(std::vector<int>& nums) {
    if (nums.empty()) return {};

    std::vector<std::string> output;

    int begin{nums.front()};
    int end{nums.front()};
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] == end + 1) {
        ++end;
      } else {
        if (begin == end) {
          output.push_back(std::to_string(begin));
        } else {
          std::stringstream ss{};
          ss << begin << "->" << end;
          output.push_back(ss.str());
        }
        begin = nums[i];
        end = nums[i];
      }
    }

    if (begin == end) {
      output.push_back(std::to_string(begin));
    } else {
      std::stringstream ss{};
      ss << begin << "->" << end;
      output.push_back(ss.str());
    }

    return output;
  }
};
