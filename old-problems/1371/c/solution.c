int findTheLongestSubstring(char* s) {
  int maskPos[32] = {
      -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
      -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2};

  int longest = 0;
  unsigned char mask = 0;
  for (int i = 0; s[i] != 0; ++i) {
    switch (s[i]) {
      case 'a':
        mask ^= 1;
        break;

      case 'e':
        mask ^= 2;
        break;

      case 'i':
        mask ^= 4;
        break;

      case 'o':
        mask ^= 8;
        break;

      case 'u':
        mask ^= 16;
        break;
    }

    if (maskPos[mask] < -1) {
      maskPos[mask] = i;
    } else if (i - maskPos[mask] > longest) {
      longest = i - maskPos[mask];
    }
  }
  return longest;
}
