int output[3];

int* memLeak(int memory1, int memory2, int* returnSize) {
  int time = 0;
  while (1) {
    ++time;
    if (memory1 >= memory2) {
      if (time > memory1) break;
      memory1 -= time;
    } else {
      if (time > memory2) break;
      memory2 -= time;
    }
  }

  output[0] = time;
  output[1] = memory1;
  output[2] = memory2;

  *returnSize = 3;
  return output;
}
