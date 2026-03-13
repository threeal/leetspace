#include <string>

extern "C" {
char* majorityFrequencyGroup(char* s);
}

std::string solution_c(std::string s) {
  return majorityFrequencyGroup(s.data());
}
