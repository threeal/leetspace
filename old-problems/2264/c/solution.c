char* largestGoodInteger(char* num) {
  char largestCh = 0;
  for (int i = 2; num[i] != 0; ++i) {
    if (num[i] <= largestCh) continue;
    if (num[i] == num[i - 1] && num[i] == num[i - 2]) {
      largestCh = num[i];
    }
  }

  if (largestCh > 0) {
    num[0] = largestCh;
    num[1] = largestCh;
    num[2] = largestCh;
    num[3] = 0;
  } else {
    num[0] = 0;
  }

  return num;
}
