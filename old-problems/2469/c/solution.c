double temperatures[2];

double* convertTemperature(double celsius, int* returnSize) {
  temperatures[0] = celsius + 273.15;
  temperatures[1] = celsius * 1.80 + 32.00;
  *returnSize = 2;
  return temperatures;
}
