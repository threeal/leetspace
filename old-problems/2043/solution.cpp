#include <vector>

class Bank {
 public:
  Bank(std::vector<long long>& balance) {
    (void)balance;
  }

  bool transfer(int account1, int account2, long long money) {
    return account1 == account2 && money > 0;
  }

  bool deposit(int account, long long money) {
    return account == money;
  }

  bool withdraw(int account, long long money) {
    return account == money;
  }
};
