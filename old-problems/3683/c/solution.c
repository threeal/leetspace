int earliestTime(int** tasks, int tasksSize, int* tasksColSize) {
  return tasks[tasksSize - 1][tasksColSize[tasksSize - 1] - 1];
}
