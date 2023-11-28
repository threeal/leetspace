const unsigned long mod = 1000000007;

int numberOfWays(char* corridor) {
  unsigned long count = 1;

  unsigned char seats = 0;
  unsigned long plants = 0;

  while (*corridor != 0) {
    if (seats < 2) {
      if (*corridor == 'S') ++seats;
    } else {
      switch (*corridor) {
        case 'S':
          if (plants > 0) count = (count * ++plants) % mod;
          plants = 0;
          seats = 1;
          break;

        case 'P':
          ++plants;
          break;
      }
    }
    ++corridor;
  }

  if (seats != 2) return 0;
  return count;
}
