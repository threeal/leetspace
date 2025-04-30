#include <string>
#include <vector>

extern "C" {
int finalValueAfterOperations(char** operations, int operationsSize);
}

int solution_c(std::vector<std::string> operations) {
  std::vector<char*> operationsDatas(operations.size());
  for (std::size_t i{0}; i < operations.size(); ++i) {
    operationsDatas[i] = operations[i].data();
  }

  return finalValueAfterOperations(operationsDatas.data(), operations.size());
}
