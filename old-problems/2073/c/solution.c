int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
  int target = tickets[k];
  int sum = target;

  for (int i = 0; i < k; ++i) {
    sum += tickets[i] < target ? tickets[i] : target;
  }

  --target;
  for (int i = k + 1; i < ticketsSize; ++i) {
    sum += tickets[i] < target ? tickets[i] : target;
  }

  return sum;
}
