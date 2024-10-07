#include <cstring>
#include <vector>

extern "C" {
int* countServers(
    int n, int** logs, int logsSize, int* logsColSize, int x,
    int* queries, int queriesSize, int* returnSize);
}

std::vector<int> solution_c(
    int n, std::vector<std::vector<int>> logs, int x,
    std::vector<int> queries) {
  std::vector<int*> logsDatas(logs.size());
  std::vector<int> logsSizes(logs.size());
  for (std::size_t i{0}; i < logs.size(); ++i) {
    logsDatas[i] = logs[i].data();
    logsSizes[i] = logs[i].size();
  }

  int returnSize{};
  const auto returnData = countServers(
      n, logsDatas.data(), logsDatas.size(), logsSizes.data(), x,
      queries.data(), queries.size(), &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
