#include <vector>

extern "C" {
bool doesValidArrayExist(int* derived, int derivedSize);
}

bool solution_c(std::vector<int> derived) {
  return doesValidArrayExist(derived.data(), derived.size());
}
