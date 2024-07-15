#include <vector>

extern "C" {
double averageWaitingTime(
    int** customers, int customersSize, int* customersColSize);
}

int solution_c(std::vector<std::vector<int>> customers) {
  std::vector<int*> customersDatas(customers.size());
  std::vector<int> customersSizes(customers.size());
  for (int i = customers.size() - 1; i >= 0; --i) {
    customersDatas[i] = customers[i].data();
    customersSizes[i] = customers[i].size();
  }

  return averageWaitingTime(
      customersDatas.data(), customersDatas.size(), customersSizes.data());
}
