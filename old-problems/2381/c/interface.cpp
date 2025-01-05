#include <string>
#include <vector>

extern "C" {
char* shiftingLetters(
    char* s, int** shifts, int shiftsSize, int* shiftsColSize);
}

std::string solution_c(std::string s, std::vector<std::vector<int>> shifts) {
  std::vector<int*> shiftsDatas(shifts.size());
  std::vector<int> shiftsSizes(shifts.size());
  for (std::size_t i{0}; i < shifts.size(); ++i) {
    shiftsDatas[i] = shifts[i].data();
    shiftsSizes[i] = shifts[i].size();
  }

  return shiftingLetters(
      s.data(), shiftsDatas.data(), shiftsDatas.size(), shiftsSizes.data());
}
