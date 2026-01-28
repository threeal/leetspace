double calculateTax(
    int** brackets, int bracketsSize, int* bracketsColSize, int income) {
  (void)bracketsSize;
  (void)bracketsColSize;

  double tax = 0;
  if (income > 0) {
    if (income <= brackets[0][0]) {
      tax += (double)income * brackets[0][1] / 100;
    } else {
      tax += (double)brackets[0][0] * brackets[0][1] / 100;

      int i = 1;
      while (brackets[i][0] < income) {
        tax += (double)(brackets[i][0] - brackets[i - 1][0]) *
            brackets[i][1] / 100;
        ++i;
      }

      tax += (double)(income - brackets[i - 1][0]) *
          brackets[i][1] / 100;
    }
  }

  return tax;
}
