class Solution {
 public:
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    map<int, int, less<int>> positions;
    for (auto person : people) {
      positions[person] = 0;
    }

    sort(flowers.begin(), flowers.end(), [](const auto& a, const auto& b) { return a[0] < b[0]; });
    auto flower = flowers.begin();

    list<int> ends;
    for (auto& [position, count] : positions) {
      while (!ends.empty() && ends.front() < position) {
        ends.pop_front();
      }

      while (flower != flowers.end() && (*flower)[0] <= position) {
        if ((*flower)[1] >= position) {
          ends.insert(lower_bound(ends.begin(), ends.end(), (*flower)[1]), (*flower)[1]);
        }
        ++flower;
      }

      count += ends.size();
    }

    for (auto& person : people) {
      person = positions[person];
    }

    return people;
  }
};
