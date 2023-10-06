#include <interface.hpp>
#include <string>

using namespace std;

#include "solution.cpp"

template <>
bool solution_cpp(const string& colors) {
  return Solution().winnerOfGame(colors);
}
