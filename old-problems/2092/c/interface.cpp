#include <cstring>
#include <vector>

extern "C" {
int* findAllPeople(
    int n, int** meetings, int meetingsSize, int* meetingsColSize,
    int firstPerson, int* returnSize);
}

std::vector<int> solution_c(
    int n, std::vector<std::vector<int>> meetings, int firstPerson) {
  std::vector<int*> meetingsDatas(meetings.size());
  std::vector<int> meetingsSizes(meetings.size());
  for (std::size_t i{0}; i < meetings.size(); ++i) {
    meetingsDatas[i] = meetings[i].data();
    meetingsSizes[i] = meetings[i].size();
  }

  int returnSize{};
  int* returnData = findAllPeople(
      n, meetingsDatas.data(), meetingsDatas.size(), meetingsSizes.data(),
      firstPerson, &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
