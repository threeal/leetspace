#include <vector>

extern "C" {
int countDays(
    int days, int** meetings, int meetingsSize, int* meetingsColSize);
}

int solution_c(int days, std::vector<std::vector<int>> meetings) {
  std::vector<int*> meetingsDatas(meetings.size());
  std::vector<int> meetingsSizes(meetings.size());
  for (std::size_t i{0}; i < meetings.size(); ++i) {
    meetingsDatas[i] = meetings[i].data();
    meetingsSizes[i] = meetings[i].size();
  }

  return countDays(
      days, meetingsDatas.data(), meetings.size(), meetingsSizes.data());
}
