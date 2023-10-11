class Solution {
 public:
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    auto positions = people;
    sort(positions.begin(), positions.end());
    positions.erase(unique(positions.begin(), positions.end()), positions.end());

    unordered_map<int, int> position_flowers;

    for (const auto& flower : flowers) {
      auto it = lower_bound(positions.begin(), positions.end(), flower[0]);
      while (it != positions.end() && *it <= flower[1]) {
        ++position_flowers[*it];
        ++it;
      }
    }

    for (auto& person : people) {
      person = position_flowers[person];
    }

    return people;
  }
};
