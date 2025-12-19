#include <string>

extern "C" {
bool checkTwoChessboards(char* coordinate1, char* coordinate2);
}

bool solution_c(std::string coordinate1, std::string coordinate2) {
  return checkTwoChessboards(coordinate1.data(), coordinate2.data());
}
