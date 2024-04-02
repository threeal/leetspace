// The solution is simple, just count the number of plants between two seats and multiply each of them.
// Tidak layak dikategorikan hard wkwk

#include <string>

const unsigned long mod = 1'000'000'007;

class Solution {
 public:
  int numberOfWays(std::string corridor) {
    unsigned long count = 1;

    unsigned char seats = 0;
    unsigned long plants = 0;

    // Iterate through each character of the corridor string.
    for (const auto c : corridor) {
      // Repeat until it finds 2 seats.
      if (seats < 2) {
        if (c == 'S') ++seats;
      } else {
        // If 2 seats are found, check the next character.
        switch (c) {
          case 'S':
            // If it is a seat, calculate the total count by multiplying it
            // with the number of plants + 1.
            if (plants > 0) count = (count * ++plants) % mod;

            // Reset the plants and seats counting.
            plants = 0;
            seats = 1;
            break;

          case 'P':
            // Count each next consecutive plant.
            ++plants;
            break;
        }
      }
    }

    // If the previous seats counting is not 2
    // then the total counting does not matter.
    if (seats != 2) return 0;

    return count;
  }
};
