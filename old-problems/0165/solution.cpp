#include <iterator>
#include <string>
#include <utility>

class Solution {
 public:
  int compareVersion(std::string version1, std::string version2) {
    auto it1 = version1.begin();
    auto it2 = version2.begin();
    while (it1 != version1.end() && it2 != version2.end()) {
      while (it1 != version1.end() && *it1 == '0') ++it1;
      auto begin1 = it1;

      while (it2 != version2.end() && *it2 == '0') ++it2;
      auto begin2 = it2;

      while (it1 != version1.end() && *it1 != '.') ++it1;
      while (it2 != version2.end() && *it2 != '.') ++it2;

      if (std::distance(begin1, it1) == std::distance(begin2, it2)) {
        while (begin1 != it1 && begin2 != it2) {
          if (*begin1 != *begin2) return *begin1 < *begin2 ? -1 : 1;
          ++begin1;
          ++begin2;
        }
      } else {
        return std::distance(begin1, it1) < std::distance(begin2, it2) ? -1 : 1;
      }

      if (it1 != version1.end()) ++it1;
      if (it2 != version2.end()) ++it2;
    }

    if (it1 != version1.end()) {
      while (it1 != version1.end()) {
        while (it1 != version1.end() && *it1 == '0') ++it1;
        if (it1 != version1.end()) {
          if (*it1 != '.') return 1;
          ++it1;
        }
      }
    } else if (it2 != version2.end()) {
      while (it2 != version2.end()) {
        while (it2 != version2.end() && *it2 == '0') ++it2;
        if (it2 != version2.end()) {
          if (*it2 != '.') return -1;
          ++it2;
        }
      }
    }

    return 0;
  }
};
