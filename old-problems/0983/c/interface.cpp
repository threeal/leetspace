#include <vector>

extern "C" {
int mincostTickets(int* days, int daysSize, int* costs, int costsSize);
}

int solution_c(std::vector<int> days, std::vector<int> costs) {
  return mincostTickets(days.data(), days.size(), costs.data(), costs.size());
}
