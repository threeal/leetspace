#include <string>
#include <vector>

extern "C" {
int openLock(char** deadends, int deadendsSize, char* target);
}

int solution_c(std::vector<std::string> deadends, std::string target) {
  std::vector<char*> deadendsDatas(deadends.size());
  for (std::size_t i{0}; i < deadends.size(); ++i) {
    deadendsDatas[i] = deadends[i].data();
  }

  return openLock(deadendsDatas.data(), deadendsDatas.size(), target.data());
}
