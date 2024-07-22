#include <string>
#include <vector>

extern "C" {
int minOperations(char** logs, int logsSize);
}

int solution_c(std::vector<std::string> logs) {
  std::vector<char*> logsDatas(logs.size());
  for (int i = logs.size() - 1; i >= 0; --i) {
    logsDatas[i] = logs[i].data();
  }

  return minOperations(logsDatas.data(), logsDatas.size());
}
