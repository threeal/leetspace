#include <vector>

extern "C" {
int timeRequiredToBuy(int* tickets, int ticketsSize, int k);
}

int solution_c(std::vector<int> tickets, int k) {
  return timeRequiredToBuy(tickets.data(), tickets.size(), k);
}
