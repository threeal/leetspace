#include <vector>

extern "C" {
int maxTwoEvents(int** events, int eventsSize, int* eventsColSize);
}

int solution_c(std::vector<std::vector<int>> events) {
  std::vector<int*> eventsDatas(events.size());
  std::vector<int> eventsSizes(events.size());
  for (std::size_t i{0}; i < events.size(); ++i) {
    eventsDatas[i] = events[i].data();
    eventsSizes[i] = events[i].size();
  }

  return maxTwoEvents(eventsDatas.data(), events.size(), eventsSizes.data());
}
