int wateringPlants(int* plants, int plantsSize, int capacity) {
  int steps = 0, water = capacity;
  for (int i = 0; i < plantsSize; ++i) {
    if (water < plants[i]) {
      steps += i + i;
      water = capacity - plants[i];
    } else {
      water -= plants[i];
    }
  }
  return steps + plantsSize;
}
