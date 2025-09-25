int numOfUnplacedFruits(
    int* fruits, int fruitsSize, int* baskets, int basketsSize) {
  int num = fruitsSize;
  for (int i = 0; i < fruitsSize; ++i) {
    for (int j = 0; j < basketsSize; ++j) {
      if (baskets[j] >= fruits[i]) {
        --num;
        baskets[j] = 0;
        break;
      }
    }
  }
  return num;
}
