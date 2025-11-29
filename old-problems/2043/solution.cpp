#include <vector>

class Bank {
 private:
  std::vector<long long> balance;
  int n;

 public:
  Bank(std::vector<long long>& balance) : balance{balance}, n(balance.size()) {}

  bool transfer(int account1, int account2, long long money) {
    if (--account1 >= n) return false;
    if (--account2 >= n) return false;
    if (balance[account1] < money) return false;
    balance[account1] -= money;
    balance[account2] += money;
    return true;
  }

  bool deposit(int account, long long money) {
    if (--account >= n) return false;
    balance[account] += money;
    return true;
  }

  bool withdraw(int account, long long money) {
    if (--account >= n) return false;
    if (balance[account] < money) return false;
    balance[account] -= money;
    return true;
  }
};
