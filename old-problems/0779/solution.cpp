class Solution {
 public:
  int kthGrammar(int n, int k) {
    // Base case: The root value is zero.
    if (n == 0) return 0;

    // Recursive logic:
    // - If the parent value is zero, children will be zero and one.
    // - If the parent value is one, children will be one and zero.
    return kthGrammar(n - 1, (k + 1) / 2) == 0
        ? (k - 1) % 2
        : k % 2;
  }
};
