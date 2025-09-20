#include <stdbool.h>

static bool judge4(int div, int a, int b, int c, int d);
static bool judge3(int div, int a, int b, int c);
static bool judge2(int div, int a, int b);
static bool judge1(int div, int a);

bool judgePoint24(int* cards, int cardsSize) {
  (void)cardsSize;
  return judge4(1, cards[0], cards[1], cards[2], cards[3]);
}

static bool judge4(int div, int a, int b, int c, int d) {
  if (judge3(div, a + b, c, d)) return true;
  if (judge3(div, a + c, b, d)) return true;
  if (judge3(div, a + d, b, c)) return true;
  if (judge3(div, b + c, a, d)) return true;
  if (judge3(div, b + d, a, c)) return true;
  if (judge3(div, c + d, a, b)) return true;

  if (judge3(div, a - b, c, d)) return true;
  if (judge3(div, a - c, b, d)) return true;
  if (judge3(div, a - d, b, c)) return true;

  if (judge3(div, b - a, c, d)) return true;
  if (judge3(div, b - c, a, d)) return true;
  if (judge3(div, b - d, a, c)) return true;

  if (judge3(div, c - a, b, d)) return true;
  if (judge3(div, c - b, a, d)) return true;
  if (judge3(div, c - d, a, b)) return true;

  if (judge3(div, d - a, b, c)) return true;
  if (judge3(div, d - b, a, c)) return true;
  if (judge3(div, d - c, a, b)) return true;

  if (judge3(div * div, a * b, c, d)) return true;
  if (judge3(div * div, a * c, b, d)) return true;
  if (judge3(div * div, a * d, b, c)) return true;
  if (judge3(div * div, b * c, a, d)) return true;
  if (judge3(div * div, b * d, a, c)) return true;
  if (judge3(div * div, c * d, a, b)) return true;

  if (judge3(div * b, a * div, c * b, d * b)) return true;
  if (judge3(div * c, a * div, b * c, d * c)) return true;
  if (judge3(div * d, a * div, b * d, c * d)) return true;

  if (judge3(div * a, b * div, c * a, d * a)) return true;
  if (judge3(div * c, b * div, a * c, d * c)) return true;
  if (judge3(div * d, b * div, a * d, c * d)) return true;

  if (judge3(div * a, c * div, b * a, d * a)) return true;
  if (judge3(div * b, c * div, a * b, d * b)) return true;
  if (judge3(div * d, c * div, a * d, b * d)) return true;

  if (judge3(div * a, d * div, b * a, c * a)) return true;
  if (judge3(div * b, d * div, a * b, c * b)) return true;
  if (judge3(div * c, d * div, a * c, b * c)) return true;

  return false;
}

static bool judge3(int div, int a, int b, int c) {
  if (div == 0) return false;

  if (judge2(div, a + b, c)) return true;
  if (judge2(div, a + c, b)) return true;
  if (judge2(div, b + c, a)) return true;

  if (judge2(div, a - b, c)) return true;
  if (judge2(div, a - c, b)) return true;

  if (judge2(div, b - a, c)) return true;
  if (judge2(div, b - c, a)) return true;

  if (judge2(div, c - a, b)) return true;
  if (judge2(div, c - b, a)) return true;

  if (judge2(div * div, a * b, c)) return true;
  if (judge2(div * div, a * c, b)) return true;
  if (judge2(div * div, b * c, a)) return true;

  if (judge2(div * b, a * div, c * b)) return true;
  if (judge2(div * c, a * div, b * c)) return true;

  if (judge2(div * a, b * div, c * a)) return true;
  if (judge2(div * c, b * div, a * c)) return true;

  if (judge2(div * a, c * div, b * a)) return true;
  if (judge2(div * b, c * div, a * b)) return true;

  return false;
}

static bool judge2(int div, int a, int b) {
  if (div == 0) return false;

  if (judge1(div, a + b)) return true;

  if (judge1(div, a - b)) return true;
  if (judge1(div, b - a)) return true;

  if (judge1(div * div, a * b)) return true;

  if (judge1(b, a)) return true;
  if (judge1(a, b)) return true;

  return false;
}

static bool judge1(int div, int a) {
  return div != 0 && a % div == 0 && a / div == 24;
}
