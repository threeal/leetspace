#include <vector>

extern "C" {
int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize);
}

int solution_c(std::vector<int> seats, std::vector<int> students) {
  return minMovesToSeat(
      seats.data(), seats.size(), students.data(), students.size());
}
