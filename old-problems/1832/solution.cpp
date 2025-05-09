#include <cstdint>
#include <string>

class Solution {
 public:
  bool checkIfPangram(std::string sentence) {
    std::uint32_t flag{0};
    for (const char c : sentence) {
      flag |= 1 << (c - 'a');
    }
    return flag == 0b11111111111111111111111111;
  }
};
