#include <vector>

extern "C" {
bool isOneBitCharacter(int* bits, int bitsSize);
}

bool solution_c(std::vector<int> bits) {
  return isOneBitCharacter(bits.data(), bits.size());
}
