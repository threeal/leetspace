int addRungs(int* rungs, int rungsSize, int dist) {
  int extraRungs = (rungs[0] - 1) / dist;
  for (int i = rungsSize - 1; i > 0; --i) {
    extraRungs += (rungs[i] - rungs[i - 1] - 1) / dist;
  }
  return extraRungs;
}
