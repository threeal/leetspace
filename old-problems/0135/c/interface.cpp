#include <vector>

extern "C" {
int candy(int* ratings, int ratingsSize);
}

int solution_c(std::vector<int> ratings) {
  return candy(ratings.data(), ratings.size());
}
