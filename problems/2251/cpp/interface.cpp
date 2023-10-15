#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#include "solution.cpp"

std::vector<int> solution_cpp(vector<vector<int>> flowers, vector<int> people) {
  return Solution().fullBloomFlowers(flowers, people);
}
