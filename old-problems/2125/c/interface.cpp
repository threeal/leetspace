#include <string>
#include <vector>

extern "C" {
int numberOfBeams(char** bank, int bankSize);
}

int solution_c(std::vector<std::string> bank) {
  std::vector<char*> bank_data(bank.size());
  for (std::size_t i = 0; i < bank.size(); ++i) {
    bank_data[i] = bank[i].data();
  }

  return numberOfBeams(bank_data.data(), bank_data.size());
}
