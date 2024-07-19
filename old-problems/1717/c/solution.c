int maximumGain(char* s, int x, int y) {
  int gain = 0;
  int aCount = 0;
  int bCount = 0;

  if (x < y) {
    for (char* c = s; *c != 0; ++c) {
      switch (*c) {
        case 'a':
          if (bCount > 0) {
            gain += y;
            --bCount;
          } else {
            ++aCount;
          }
          break;

        case 'b':
          ++bCount;
          break;

        default:
          gain += (aCount < bCount ? aCount : bCount) * x;
          aCount = 0;
          bCount = 0;
      }
    }

    return gain + (aCount < bCount ? aCount : bCount) * x;
  }

  for (char* c = s; *c != 0; ++c) {
    switch (*c) {
      case 'a':
        ++aCount;
        break;

      case 'b':
        if (aCount > 0) {
          gain += x;
          --aCount;
        } else {
          ++bCount;
        }
        break;

      default:
        gain += (aCount < bCount ? aCount : bCount) * y;
        aCount = 0;
        bCount = 0;
    }
  }

  return gain + (aCount < bCount ? aCount : bCount) * y;
}
