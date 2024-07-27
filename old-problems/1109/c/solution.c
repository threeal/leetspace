#include <stdlib.h>

int* corpFlightBookings(
    int** bookings, int bookingsSize, int* bookingsColSize,
    int n, int* returnSize) {
  (void)bookings;
  (void)bookingsSize;
  (void)bookingsColSize;
  *returnSize = n;
  return malloc(*returnSize * sizeof(int));
}
