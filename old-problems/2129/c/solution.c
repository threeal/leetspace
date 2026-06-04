char* capitalizeTitle(char* title) {
  int r = 0;
  while (1) {
    const int l = r++;
    while (title[r] != 0 && title[r] != ' ') {
      if (title[r] < 'a') title[r] += 'a' - 'A';
      ++r;
    }

    if (r - l > 2) {
      if (title[l] >= 'a') title[l] -= 'a' - 'A';
    } else {
      if (title[l] < 'a') title[l] += 'a' - 'A';
    }

    if (title[r] == 0) break;
    ++r;
  }
  return title;
}
