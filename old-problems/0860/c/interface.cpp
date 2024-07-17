#include <vector>

extern "C" {
bool lemonadeChange(int* bills, int billsSize);
}

bool solution_c(std::vector<int> bills) {
  return lemonadeChange(bills.data(), bills.size());
}
