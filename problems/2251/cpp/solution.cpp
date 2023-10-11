class Solution {
 public:
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    map<int, int, less<int>> positions;
    for (auto person : people) {
      positions[person] = 0;
    }

    sort(flowers.begin(), flowers.end(), [](const auto& a, const auto& b) { return a[0] < b[0]; });
    auto flower = flowers.begin();

    vector<int> ends;
    for (auto& position : positions) {
      ends.erase(
          remove_if(ends.begin(), ends.end(), [=](auto end) { return end < position.first; }), ends.end());

      while (flower != flowers.end() && (*flower)[0] <= position.first) {
        if ((*flower)[1] >= position.first) {
          ends.push_back((*flower)[1]);
        }
        ++flower;
      }

      position.second += ends.size();
    }

    for (auto& person : people) {
      person = positions[person];
    }

    return people;
  }
};
