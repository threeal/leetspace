char* categorizeBox(int length, int width, int height, int mass) {
  if (length >= 10000 || width >= 10000 || height >= 10000 ||
      (long long)length * width * height >= 1000000000) {
    return mass >= 100 ? "Both" : "Bulky";
  }
  return mass >= 100 ? "Heavy" : "Neither";
}
