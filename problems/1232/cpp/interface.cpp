#include <interface.hpp>
#include <vector>

using namespace std;

#include "solution.cpp"

template <>
bool solution_cpp(const vector<vector<int>>& coordinates) {
  auto coordinates_copy = coordinates;
  return Solution().checkStraightLine(coordinates_copy);
}
