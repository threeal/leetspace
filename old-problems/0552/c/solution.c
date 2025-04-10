static int sum(int a, int b) {
  return (a + b) % 1000000007;
}

int checkRecord(int n) {
  int buff[12] = {1, 1, 0, 1};
  int* curr = buff;
  int* prev = buff + 6;

  while (--n > 0) {
    int* temp = curr;
    curr = prev;
    prev = temp;

    curr[0] = sum(sum(prev[0], prev[1]), prev[2]);
    curr[1] = prev[0];
    curr[2] = prev[1];
    curr[3] = sum(sum(sum(sum(sum(prev[0], prev[1]), prev[2]), prev[3]), prev[4]), prev[5]);
    curr[4] = prev[3];
    curr[5] = prev[4];
  }

  return sum(sum(sum(sum(sum(curr[0], curr[1]), curr[2]), curr[3]), curr[4]), curr[5]);
}
