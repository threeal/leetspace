#include <vector>

extern "C" {
int maximumWealth(int** accounts, int accountsSize, int* accountsColSize);
}

int solution_c(std::vector<std::vector<int>> accounts) {
  std::vector<int*> accountsDatas(accounts.size());
  std::vector<int> accountsSizes(accounts.size());
  for (std::size_t i{0}; i < accounts.size(); ++i) {
    accountsDatas[i] = accounts[i].data();
    accountsSizes[i] = accounts[i].size();
  }

  return maximumWealth(
      accountsDatas.data(), accounts.size(), accountsSizes.data());
}
