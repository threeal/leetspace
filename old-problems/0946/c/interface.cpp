#include <vector>

extern "C" {
bool validateStackSequences(
    int* pushed, int pushedSize, int* popped, int poppedSize);
}

bool solution_c(std::vector<int> pushed, std::vector<int> popped) {
  return validateStackSequences(
      pushed.data(), pushed.size(), popped.data(), popped.size());
}
