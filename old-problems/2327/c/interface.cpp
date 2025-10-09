extern "C" {
int peopleAwareOfSecret(int n, int delay, int forget);
}

int solution_c(int n, int delay, int forget) {
  return peopleAwareOfSecret(n, delay, forget);
}
