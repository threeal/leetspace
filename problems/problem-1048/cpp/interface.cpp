#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#include "solution.cpp"

int solution_cpp(std::vector<std::string>& words) {
  return Solution().longestStrChain(words);
}
