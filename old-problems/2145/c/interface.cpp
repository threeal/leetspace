#include <vector>

extern "C" {
int numberOfArrays(
    int* differences, int differencesSize, int lower, int upper);
}

int solution_c(std::vector<int> differences, int lower, int upper) {
  return numberOfArrays(differences.data(), differences.size(), lower, upper);
}
