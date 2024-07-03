int minEatingSpeed(int* piles, int pilesSize, int h) {
  int left = 1;

  int right = piles[0];
  for (int i = pilesSize - 1; i > 0; --i) {
    if (piles[i] > right) right = piles[i];
  }

  while (left < right) {
    const int mid = (left + right) / 2;

    int time = 0;
    for (int i = pilesSize - 1; i >= 0; --i) {
      time += piles[i] / mid;
      if (piles[i] % mid > 0) ++time;
      if (time > h) break;
    }

    if (time > h) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return left;
}
