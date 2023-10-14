#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#include "solution.cpp"

int solution_cpp(const std::vector<std::string>& words) {
  auto words_copy = words;
  return Solution().longestStrChain(words_copy);
}
