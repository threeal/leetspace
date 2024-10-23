#include <vector>

extern "C" {
int maxEvents(int** events, int eventsSize, int* eventsColSize);
}

int solution_c(std::vector<std::vector<int>> events) {
  std::vector<int*> eventsDatas(events.size());
  std::vector<int> eventsSizes(events.size());
  for (int i = events.size() - 1; i >= 0; --i) {
    eventsDatas[i] = events[i].data();
    eventsSizes[i] = events[i].size();
  }

  return maxEvents(eventsDatas.data(), eventsDatas.size(), eventsSizes.data());
}
