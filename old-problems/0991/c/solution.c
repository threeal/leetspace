int brokenCalc(int startValue, int target) {
  int operations = 0;
  while (target > startValue) {
    ++operations;
    if (target % 2 == 0) {
      target /= 2;
    } else {
      target += 1;
    }
  }
  return operations + startValue - target;
}
