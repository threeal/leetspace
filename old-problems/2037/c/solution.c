#include <stdlib.h>

int comp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int minMovesToSeat(
    int* seats, int seatsSize, int* students, int studentsSize) {
  qsort(seats, seatsSize, sizeof(int), comp);
  qsort(students, studentsSize, sizeof(int), comp);

  int moves = 0;
  for (int i = seatsSize - 1; i >= 0; --i) {
    moves += abs(seats[i] - students[i]);
  }

  return moves;
}
