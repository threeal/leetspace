#include <functional>
#include <interface.hpp>
#include <vector>

using namespace std;

#include "solution.cpp"

template <>
vector<int> solution_cpp(const int& rowIndex) {
  return Solution().getRow(rowIndex);
}
