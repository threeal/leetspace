#include <vector>

extern "C" {
bool mergeTriplets(
    int** triplets, int tripletsSize, int* tripletsColSize,
    int* target, int targetSize);
}

bool solution_c(std::vector<std::vector<int>> triplets, std::vector<int> target) {
  std::vector<int*> tripletsDatas(triplets.size());
  std::vector<int> tripletsSizes(triplets.size());
  for (std::size_t i{0}; i < triplets.size(); ++i) {
    tripletsDatas[i] = triplets[i].data();
    tripletsSizes[i] = triplets[i].size();
  }

  return mergeTriplets(
      tripletsDatas.data(), triplets.size(), tripletsSizes.data(),
      target.data(), target.size());
}
