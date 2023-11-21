#include <string>
#include <vector>

extern "C" {
int garbageCollection(char** garbage, int garbageSize, int* travel, int travelSize);
}

int solution_c(std::vector<std::string> garbage, std::vector<int> travel) {
  std::vector<char*> garbagePtr(garbage.size());
  for (size_t i = 0; i < garbage.size(); ++i) {
    garbagePtr[i] = garbage[i].data();
  }

  return garbageCollection(garbagePtr.data(), garbagePtr.size(), travel.data(), travel.size());
}
