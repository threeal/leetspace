int shipWithinDays(int* weights, int weightsSize, int days) {
  int low = 1, high = 0;
  for (int i = 0; i < weightsSize; ++i) high += weights[i];

  while (low < high) {
    const int mid = low + (high - low) / 2;

    int count = 1, sum = 0;
    for (int i = 0; i < weightsSize; ++i) {
      if (sum + weights[i] > mid) {
        if (weights[i] > mid || ++count > days) {
          count = days + 1;
          break;
        }
        sum = weights[i];
      } else {
        sum += weights[i];
      }
    }

    if (count > days) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return low;
}
