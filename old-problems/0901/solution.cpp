#include <stack>

struct Stock {
  int price;
  int count;
};

class StockSpanner {
 private:
  std::stack<Stock> stocks;

 public:
  StockSpanner() : stocks{} {}

  int next(int price) {
    int count{1};
    while (!stocks.empty() && stocks.top().price <= price) {
      count += stocks.top().count;
      stocks.pop();
    }
    stocks.push({.price = price, .count = count});
    return count;
  }
};
