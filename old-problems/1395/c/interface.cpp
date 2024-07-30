#include <vector>

extern "C" {
int numTeams(int* rating, int ratingSize);
}

int solution_c(std::vector<int> rating) {
  return numTeams(rating.data(), rating.size());
}
