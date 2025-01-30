#include <vector>

extern "C" {
bool* checkIfPrerequisite(
    int numCourses,
    int** prerequisites, int prerequisitesSize, int* prerequisitesColSize,
    int** queries, int queriesSize, int* queriesColSize, int* returnSize);
}

std::vector<bool> solution_c(
    int numCourses, std::vector<std::vector<int>> prerequisites,
    std::vector<std::vector<int>> queries) {
  std::vector<int*> prerequisitesDatas(prerequisites.size());
  std::vector<int> prerequisitesSizes(prerequisites.size());
  for (std::size_t i{0}; i < prerequisites.size(); ++i) {
    prerequisitesDatas[i] = prerequisites[i].data();
    prerequisitesSizes[i] = prerequisites[i].size();
  }

  std::vector<int*> queriesDatas(queries.size());
  std::vector<int> queriesSizes(queries.size());
  for (std::size_t i{0}; i < queries.size(); ++i) {
    queriesDatas[i] = queries[i].data();
    queriesSizes[i] = queries[i].size();
  }

  int returnSize{};
  bool* returnData = checkIfPrerequisite(
      numCourses, prerequisitesDatas.data(), prerequisitesDatas.size(),
      prerequisitesSizes.data(), queriesDatas.data(), queriesDatas.size(),
      queriesSizes.data(), &returnSize);

  std::vector<bool> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i] = returnData[i];
  }

  return output;
}
