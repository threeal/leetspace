class Solution {
 public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    int forgetCounts[10001]{0};
    int shareCounts[10001]{0};

    forgetCounts[forget] = 1;
    shareCounts[delay] = 1;

    int people{1}, sharingPeople{0};
    for (int i{1}; i < n; ++i) {
      sharingPeople = ((sharingPeople + shareCounts[i]) % 1000000007 + 1000000007 - forgetCounts[i]) % 1000000007;
      people = ((people + sharingPeople) % 1000000007 + 1000000007 - forgetCounts[i]) % 1000000007;

      forgetCounts[i + forget] = sharingPeople;
      shareCounts[i + delay] = sharingPeople;
    }

    return people;
  }
};
