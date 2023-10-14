#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#include "solution.cpp"

std::vector<int> solution_cpp(const std::vector<std::vector<int>>& flowers, const std::vector<int>& people) {
  auto flowers_copy = flowers;
  auto people_copy = people;
  return Solution().fullBloomFlowers(flowers_copy, people_copy);
}
