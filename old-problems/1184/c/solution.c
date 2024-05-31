int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination) {
  if (start == destination) return 0;
  if (destination < start) {
    const int temp = destination;
    destination = start;
    start = temp;
  }

  int forwardDistance = 0;
  for (int i = start; i < destination; ++i) forwardDistance += distance[i];

  int backwardDistance = 0;
  for (int i = destination; i < distanceSize; ++i) backwardDistance += distance[i];
  for (int i = start - 1; i >= 0; --i) backwardDistance += distance[i];

  return forwardDistance < backwardDistance ? forwardDistance : backwardDistance;
}
