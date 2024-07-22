int minOperations(char** logs, int logsSize) {
  int level = 0;
  for (int i = 0; i < logsSize; ++i) {
    if (logs[i][0] == '.') {
      if (logs[i][1] == '.' && level > 0) --level;
    } else {
      ++level;
    }
  }
  return level;
}
