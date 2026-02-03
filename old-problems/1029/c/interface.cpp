#include <vector>

extern "C" {
int twoCitySchedCost(int** costs, int costsSize, int* costsColSize);
}

int solution_c(std::vector<std::vector<int>> costs) {
  std::vector<int*> costsDatas(costs.size());
  std::vector<int> costsSizes(costs.size());
  for (std::size_t i{0}; i < costs.size(); ++i) {
    costsDatas[i] = costs[i].data();
    costsSizes[i] = costs[i].size();
  }

  return twoCitySchedCost(costsDatas.data(), costs.size(), costsSizes.data());
}
