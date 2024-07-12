#include <vector>

class Cashier {
 private:
  int n;
  int count;

  double discount;
  std::vector<double> pricesOf;

 public:
  Cashier(
      int n, int discount,
      std::vector<int>& products, std::vector<int>& prices)
      : n{n}, count{n}, discount{1.0 - discount / 100.0}, pricesOf(201, 0.0) {
    for (int i = products.size() - 1; i >= 0; --i) {
      pricesOf[products[i]] = prices[i];
    }
  }

  double getBill(std::vector<int> product, std::vector<int> amount) {
    double bill{0};
    for (int i = product.size() - 1; i >= 0; --i) {
      bill += pricesOf[product[i]] * amount[i];
    }

    if (--count == 0) {
      count = n;
      bill *= discount;
    }

    return bill;
  }
};
