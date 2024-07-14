char* reformatDate(char* date) {
  char* c = date;

  char d1 = '0', d2 = '0';
  if (c[1] > '9') {
    d2 = c[0];
    c += 4;
  } else {
    d1 = c[0];
    d2 = c[1];
    c += 5;
  }

  char m1 = '0', m2 = '0';
  switch (c[0]) {
    case 'J':
      m2 = c[1] == 'a' ? '1' : (c[2] == 'n' ? '6' : '7');
      break;

    case 'F':
      m2 = '2';
      break;

    case 'M':
      m2 = c[2] == 'r' ? '3' : '5';
      break;

    case 'A':
      m2 = c[1] == 'p' ? '4' : '8';
      break;

    case 'S':
      m2 = '9';
      break;

    case 'O':
      m1 = '1';
      break;

    case 'N':
      m1 = '1';
      m2 = '1';
      break;

    case 'D':
      m1 = '1';
      m2 = '2';
      break;
  }

  date[0] = c[4];
  date[1] = c[5];
  date[2] = c[6];
  date[3] = c[7];
  date[4] = '-';
  date[5] = m1;
  date[6] = m2;
  date[7] = '-';
  date[8] = d1;
  date[9] = d2;
  date[10] = 0;

  return date;
}
