class Solution {
 public:
  std::vector<std::vector<int>> findSolution(
      CustomFunction& customfunction, int z) {
    customfunction(z, z);
    return {};
  }
};
