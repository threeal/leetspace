int maxTaskAssign(
    int* tasks, int tasksSize, int* workers, int workersSize,
    int pills, int strength) {
  return tasks[tasksSize - 1] + workers[workersSize - 1] + pills + strength;
}
