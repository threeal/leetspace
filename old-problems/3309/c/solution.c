int maxGoodNumber(int* nums, int numsSize) {
  (void)numsSize;

  const int a = nums[0], an = 32 - __builtin_clz(a);
  const int b = nums[1], bn = 32 - __builtin_clz(b);
  const int c = nums[2], cn = 32 - __builtin_clz(c);

  const int bc = b << cn | c, cb = c << bn | b;
  const int aa = a << (bn + cn) | (bc > cb ? bc : cb);

  const int ac = a << cn | c, ca = c << an | a;
  const int bb = b << (an + cn) | (ac > ca ? ac : ca);

  const int aabb = aa > bb ? aa : bb;
  const int ab = a << bn | b, ba = b << an | a;
  const int cc = c << (an + bn) | (ab > ba ? ab : ba);

  return aabb > cc ? aabb : cc;
}
