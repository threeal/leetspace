#include <string>

extern "C" {
int minPartitions(char* n);
}

int solution_c(std::string n) {
  return minPartitions(n.data());
}
