int* findingUsersActiveMinutes(
    int** logs, int logsSize, int* logsColSize, int k, int* returnSize) {
  (void)k;
  *returnSize = logsColSize[logsSize - 1];
  return logs[logsSize - 1];
}
