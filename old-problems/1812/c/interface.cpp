#include <string>

extern "C" {
bool squareIsWhite(char* coordinates);
}

bool solution_c(std::string coordinates) {
  return squareIsWhite(coordinates.data());
}
