int furthestDistanceFromOrigin(char* moves) {
  int l = 0, r = 0, _ = 0;
  for (char* c = moves; *c != 0; ++c) {
    switch (*c) {
      case 'L':
        ++l;
        break;
      case 'R':
        ++r;
        break;
      case '_':
        ++_;
        break;
    }
  }
  return l > r ? l + _ - r : r + _ - l;
}
