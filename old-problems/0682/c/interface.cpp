#include <string>
#include <vector>

extern "C" {
int calPoints(char** operations, int operationsSize);
}

int solution_c(std::vector<std::string> operations) {
  std::vector<char*> operationsDatas(operations.size());
  for (std::size_t i{0}; i < operations.size(); ++i) {
    operationsDatas[i] = operations[i].data();
  }

  return calPoints(operationsDatas.data(), operations.size());
}
