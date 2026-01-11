#include <string>

extern "C" {
int bestClosingTime(char* customers);
}

int solution_c(std::string customers) {
  return bestClosingTime(customers.data());
}
