#include <vector>

class MovieRentingSystem {
 public:
  MovieRentingSystem(int n, std::vector<std::vector<int>>& entries) {
    (void)n;
    (void)entries;
  }

  std::vector<int> search(int movie) {
    (void)movie;
    return {};
  }

  void rent(int shop, int movie) {
    (void)shop;
    (void)movie;
  }

  void drop(int shop, int movie) {
    (void)shop;
    (void)movie;
  }

  std::vector<std::vector<int>> report() {
    return {};
  }
};
