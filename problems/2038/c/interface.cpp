#include <interface.hpp>
#include <string>

extern "C" {
bool winnerOfGame(char* colors);
}

template <>
bool solution_c(const std::string& colors) {
  auto colors_copy = colors;
  return winnerOfGame(colors_copy.data());
}
