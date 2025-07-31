#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> stringSequence(std::string target) {
    std::vector<std::string> screens{};
    std::string screen{};
    while (screen.size() < target.size()) {
      screen += 'a';
      screens.push_back(screen);

      const std::size_t i{screen.size() - 1};
      while (screen[i] != target[i]) {
        ++screen[i];
        screens.push_back(screen);
      }
    }
    return screens;
  }
};
