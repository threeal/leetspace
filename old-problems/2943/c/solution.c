int maximizeSquareHoleArea(
    int n, int m, int* hBars, int hBarsSize, int* vBars, int vBarsSize) {
  return n + m + hBars[hBarsSize - 1] + vBars[vBarsSize - 1];
}
