#include <stdlib.h>

char* intToRoman(int num) {
  char* str = malloc(16 * sizeof(char));
  char* it = str;

  while (num >= 1000) {
    *it = 'M';
    ++it;
    num -= 1000;
  }

  if (num >= 900) {
    it[0] = 'C';
    it[1] = 'M';
    it += 2;
    num -= 900;
  } else if (num >= 600) {
    *it = 'D';
    ++it;
    while (num >= 600) {
      *it = 'C';
      ++it;
      num -= 100;
    }
    num -= 500;
  } else if (num >= 500) {
    *it = 'D';
    ++it;
    num -= 500;
  } else if (num >= 400) {
    it[0] = 'C';
    it[1] = 'D';
    it += 2;
    num -= 400;
  } else {
    while (num >= 100) {
      *it = 'C';
      ++it;
      num -= 100;
    }
  }

  if (num >= 90) {
    it[0] = 'X';
    it[1] = 'C';
    it += 2;
    num -= 90;
  } else if (num >= 60) {
    *it = 'L';
    ++it;
    while (num >= 60) {
      *it = 'X';
      ++it;
      num -= 10;
    }
    num -= 50;
  } else if (num >= 50) {
    *it = 'L';
    ++it;
    num -= 50;
  } else if (num >= 40) {
    it[0] = 'X';
    it[1] = 'L';
    it += 2;
    num -= 40;
  } else {
    while (num >= 10) {
      *it = 'X';
      ++it;
      num -= 10;
    }
  }

  if (num >= 9) {
    it[0] = 'I';
    it[1] = 'X';
    it += 2;
    num -= 9;
  } else if (num >= 6) {
    *it = 'V';
    ++it;
    while (num >= 6) {
      *it = 'I';
      ++it;
      num -= 1;
    }
    num -= 5;
  } else if (num >= 5) {
    *it = 'V';
    ++it;
    num -= 5;
  } else if (num >= 4) {
    it[0] = 'I';
    it[1] = 'V';
    it += 2;
    num -= 4;
  } else {
    while (num >= 1) {
      *it = 'I';
      ++it;
      num -= 1;
    }
  }

  *it = 0;
  return str;
}
