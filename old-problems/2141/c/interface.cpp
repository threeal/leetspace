#include <vector>

extern "C" {
long long maxRunTime(int n, int* batteries, int batteriesSize);
}

long long solution_c(int n, std::vector<int> batteries) {
  return maxRunTime(n, batteries.data(), batteries.size());
}
