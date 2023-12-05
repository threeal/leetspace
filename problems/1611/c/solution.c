// IDK man, see this: https://en.wikipedia.org/wiki/Gray_code#Converting_to_and_from_Gray_code

int minimumOneBitOperations(int n) {
  n ^= n >> 16;
  n ^= n >> 8;
  n ^= n >> 4;
  n ^= n >> 2;
  n ^= n >> 1;
  return n;
}
