#include <string>

extern "C" {
int numberOfRounds(char* loginTime, char* logoutTime);
}

int solution_c(std::string loginTime, std::string logoutTime) {
  return numberOfRounds(loginTime.data(), logoutTime.data());
}
