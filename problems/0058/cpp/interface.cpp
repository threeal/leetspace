#include <interface.hpp>
#include <string>

using namespace std;

#include "solution.cpp"

template <>
int solution_cpp(const std::string& s) {
  return Solution().lengthOfLastWord(s);
}
