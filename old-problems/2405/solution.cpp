#include <cstdint>
#include <string>

class Solution {
 public:
  int partitionString(std::string s) {
    int partitions{1};
    std::uint32_t flags{0};
    for (const char c : s) {
      const std::uint32_t flag{1u << (c - 'a')};
      if ((flags & flag) == 0) {
        flags |= flag;
      } else {
        flags = flag;
        ++partitions;
      }
    }
    return partitions;
  }
};
