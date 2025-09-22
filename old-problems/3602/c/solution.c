char buff[12];

char* concatHex36(int n) {
  int r = 0;

  int val = n * n * n;
  while (val > 0) {
    buff[r++] = val % 36 < 10 ? ('0' + val % 36) : ('A' + val % 36 - 10);
    val /= 36;
  }

  val = n * n;
  while (val > 0) {
    buff[r++] = val % 16 < 10 ? ('0' + val % 16) : ('A' + val % 16 - 10);
    val /= 16;
  }

  buff[r--] = 0;

  for (int l = 0; l < r; ++l, --r) {
    const int temp = buff[l];
    buff[l] = buff[r];
    buff[r] = temp;
  }

  return buff;
}
