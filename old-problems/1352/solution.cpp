#include <vector>

class ProductOfNumbers {
 private:
  std::vector<int> products;
  std::size_t n;

 public:
  ProductOfNumbers() : products{}, n{0} {}

  void add(int num) {
    if (num == 0) {
      n = 0;
    } else {
      if (n > 0) num *= products[n - 1];
      if (n >= products.size()) {
        products.push_back(num);
      } else {
        products[n] = num;
      }
      ++n;
    }
  }

  int getProduct(int k) {
    if (static_cast<std::size_t>(k) > n) return 0;
    return static_cast<std::size_t>(k) < n
        ? products[n - 1] / products[n - k - 1]
        : products[n - 1];
  }
};
