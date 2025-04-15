static long long numberOfPowerfulIntBelow(
    long long max, long long limit, long long spow, long long suffix);

long long numberOfPowerfulInt(
    long long start, long long finish, int limit, char* s) {
  long long pow = 1, suffix = 0;
  while (*s != 0) {
    pow *= 10;
    suffix = suffix * 10 + *s - '0';
    ++s;
  }

  return numberOfPowerfulIntBelow(finish, limit, pow, suffix) -
      numberOfPowerfulIntBelow(start - 1, limit, pow, suffix);
}

static long long numberOfPowerfulIntBelow(
    long long max, long long limit, long long spow, long long suffix) {
  long long pow = spow, comb = 1;
  while (pow * 10 <= max) {
    pow *= 10;
    comb *= limit + 1;
  }

  long long num = 0;
  while (pow >= spow) {
    if (max / pow > limit) {
      return num + (limit + 1) * comb;
    } else {
      num += (max / pow) * comb;
      max %= pow;
      pow /= 10;
      comb /= limit + 1;
    }
  }

  return max >= suffix ? num + 1 : num;
}
