int findKthNumber(int n, int k) {
  int num = 1;

  --k;
  while (k > 0) {
    int count = 0;
    long long curr = num, next = num + 1;
    while (curr <= n && count <= k) {
      count += (next < n + 1 ? next : n + 1) - curr;
      curr *= 10;
      next *= 10;
    }

    if (count <= k) {
      ++num;
      k -= count;
    } else {
      num *= 10;
      --k;
    }
  }

  return num;
}
