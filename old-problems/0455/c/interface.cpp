#include <vector>

extern "C" {
int findContentChildren(int* g, int gSize, int* s, int sSize);
}

int solution_c(std::vector<int> g, std::vector<int> s) {
  return findContentChildren(g.data(), g.size(), s.data(), s.size());
}
