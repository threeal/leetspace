bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
  // Special case: if start and finish are the same, time to reach cannot be 1.
  if (sx == fx && sy == fy && t == 1) return false;

  // Time to reach is equal to the largest distance between x and y axes.
  return abs(fx - sx) <= t && abs(fy - sy) <= t;
}
