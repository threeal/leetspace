#include <string>
#include <vector>

extern "C" {
int finalPositionOfSnake(int n, char** commands, int commandsSize);
}

int solution_c(int n, std::vector<std::string> commands) {
  std::vector<char*> commandsDatas(commands.size());
  for (std::size_t i{0}; i < commands.size(); ++i) {
    commandsDatas[i] = commands[i].data();
  }

  return finalPositionOfSnake(n, commandsDatas.data(), commands.size());
}
