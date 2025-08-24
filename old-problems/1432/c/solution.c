int maxDiff(int num) {
  int exp = 1;
  while (exp * 10 <= num) exp *= 10;

  int max = num;
  for (int i = exp; i > 0; i /= 10) {
    if (max / i % 10 != 9) {
      const int digit = max / i % 10;
      max += (9 - digit) * i;
      while ((i /= 10) > 0) {
        if (max / i % 10 == digit) {
          max += (9 - digit) * i;
        }
      }
    }
  }

  const int digit = num / exp % 10;
  if (digit == 1) {
    exp /= 10;
    while (exp > 0 && (num / exp % 10) <= 1) {
      exp /= 10;
    }

    if (exp > 0) {
      const int digit = num / exp % 10;
      num -= digit * exp;
      while ((exp /= 10) > 0) {
        if (num / exp % 10 == digit) {
          num -= digit * exp;
        }
      }
    }
  } else {
    num -= (digit - 1) * exp;
    while ((exp /= 10) > 0) {
      if (num / exp % 10 == digit) {
        num -= (digit - 1) * exp;
      }
    }
  }

  return max - num;
}
