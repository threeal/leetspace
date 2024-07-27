#include <stdlib.h>

int* corpFlightBookings(
    int** bookings, int bookingsSize, int* bookingsColSize,
    int n, int* returnSize) {
  (void)bookingsColSize;
  int* seats = calloc(n + 1, sizeof(int));

  for (int i = bookingsSize - 1; i >= 0; --i) {
    seats[bookings[i][0] - 1] += bookings[i][2];
    seats[bookings[i][1]] -= bookings[i][2];
  }

  for (int i = 1; i < n; ++i) {
    seats[i] += seats[i - 1];
  }

  *returnSize = n;
  return seats;
}
