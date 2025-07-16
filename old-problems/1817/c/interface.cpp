#include <cstring>
#include <vector>

extern "C" {
int* findingUsersActiveMinutes(
    int** logs, int logsSize, int* logsColSize, int k, int* returnSize);
}

std::vector<int> solution_c(std::vector<std::vector<int>> logs, int k) {
  std::vector<int*> logsDatas(logs.size());
  std::vector<int> logsSizes(logs.size());
  for (std::size_t i{0}; i < logs.size(); ++i) {
    logsDatas[i] = logs[i].data();
    logsSizes[i] = logs[i].size();
  }

  int returnSize{};
  int* returnData{
      findingUsersActiveMinutes(
          logsDatas.data(), logs.size(), logsSizes.data(), k, &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, output.size() * sizeof(int));

  return output;
}
