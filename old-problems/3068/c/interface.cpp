#include <vector>

extern "C" {
long long maximumValueSum(int* nums, int numsSize, int k, int** edges, int edgesSize, int* edgesColSize);
}

long long solution_c(std::vector<int> nums, int k, std::vector<std::vector<int>> edges) {
  std::vector<int*> edgesDatas(edges.size());
  std::vector<int> edgesSizes(edges.size());
  for (int i = edges.size() - 1; i >= 0; --i) {
    edgesDatas[i] = edges[i].data();
    edgesSizes[i] = edges[i].size();
  }

  return maximumValueSum(nums.data(), nums.size(), k, edgesDatas.data(), edgesDatas.size(), edgesSizes.data());
}
