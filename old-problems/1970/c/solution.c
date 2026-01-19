int latestDayToCross(
    int row, int col, int** cells, int cellsSize, int* cellsColSize) {
  return row + col + cells[cellsSize - 1][cellsColSize[cellsSize - 1] - 1];
}
