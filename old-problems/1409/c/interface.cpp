#include <cstring>
#include <vector>

extern "C" {
int* processQueries(int* queries, int queriesSize, int m, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> queries, int m) {
  int returnSize{};
  int* returnData{
      processQueries(queries.data(), queries.size(), m, &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
