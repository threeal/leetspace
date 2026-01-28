#include <vector>

extern "C" {
int distributeCookies(int* cookies, int cookiesSize, int k);
}

int solution_c(std::vector<int> cookies, int k) {
  return distributeCookies(cookies.data(), cookies.size(), k);
}
