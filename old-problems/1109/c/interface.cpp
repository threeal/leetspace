#include <cstring>
#include <vector>

extern "C" {
int* corpFlightBookings(
    int** bookings, int bookingsSize, int* bookingsColSize,
    int n, int* returnSize);
}

std::vector<int> solution_c(std::vector<std::vector<int>> bookings, int n) {
  std::vector<int*> bookingsDatas(bookings.size());
  std::vector<int> bookingsSizes(bookings.size());
  for (int i = bookings.size() - 1; i >= 0; --i) {
    bookingsDatas[i] = bookings[i].data();
    bookingsSizes[i] = bookings[i].size();
  }

  int returnSize{};
  const auto returnData = corpFlightBookings(
      bookingsDatas.data(), bookingsDatas.size(), bookingsSizes.data(),
      n, &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
