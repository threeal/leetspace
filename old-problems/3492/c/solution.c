int maxContainers(int n, int w, int maxWeight) {
  return n * n <= maxWeight / w ? n * n : maxWeight / w;
}
