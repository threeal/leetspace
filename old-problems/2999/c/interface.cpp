#include <string>

extern "C" {
long long numberOfPowerfulInt(
    long long start, long long finish, int limit, char* s);
}

long long solution_c(
    long long start, long long finish, int limit, std::string s) {
  return numberOfPowerfulInt(start, finish, limit, s.data());
}
