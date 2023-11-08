extern "C" {
bool isReachableAtTime(int sx, int sy, int fx, int fy, int t);
}

bool solution_c(int sx, int sy, int fx, int fy, int t) {
  return isReachableAtTime(sx, sy, fx, fy, t);
}
