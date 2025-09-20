#include <vector>

extern "C" {
int mostBooked(int n, int** meetings, int meetingsSize, int* meetingsColSize);
}

int solution_c(int n, std::vector<std::vector<int>> meetings) {
  std::vector<int*> meetingsDatas(meetings.size());
  std::vector<int> meetingsSizes(meetings.size());
  for (std::size_t i{0}; i < meetings.size(); ++i) {
    meetingsDatas[i] = meetings[i].data();
    meetingsSizes[i] = meetings[i].size();
  }

  return mostBooked(
      n, meetingsDatas.data(), meetings.size(), meetingsSizes.data());
}
