#include <vector>

class TopVotedCandidate {
 private:
  std::vector<int> topPersons;
  std::vector<int> times;

 public:
  TopVotedCandidate(
      std::vector<int>& persons, std::vector<int>& times)
      : topPersons(persons.size()), times{times} {
    std::vector<int> votes(persons.size(), 0);
    int topPerson{0};
    for (std::size_t i{0}; i < persons.size(); ++i) {
      if (++votes[persons[i]] >= votes[topPerson]) topPerson = persons[i];
      topPersons[i] = topPerson;
    }
  }

  int q(int t) {
    if (t >= times.back()) return topPersons.back();

    std::size_t low{0}, high{times.size() - 1};
    while (low < high) {
      const std::size_t mid{high - (high - low) / 2};
      if (times[mid] > t) {
        high = mid - 1;
      } else {
        low = mid;
      }
    }

    return topPersons[low];
  }
};
