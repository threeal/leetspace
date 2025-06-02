#include <string>

extern "C" {
int countBalancedPermutations(char* num);
}

int solution_c(std::string num) {
  return countBalancedPermutations(num.data());
}
