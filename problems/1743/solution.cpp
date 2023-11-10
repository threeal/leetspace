class Solution {
 public:
  vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    unordered_map<int, list<int>> adjacents;
    for (const auto& pair : adjacentPairs) {
      adjacents[pair[0]].push_back(pair[1]);
      adjacents[pair[1]].push_back(pair[0]);
    }

    const auto begin = find_if(adjacents.begin(), adjacents.end(), [](const auto& pair) {
      return pair.second.size() == 1;
    });

    vector<int> res(adjacentPairs.size() + 1);
    res[0] = begin->first;

    int prev = begin->first;
    int current = begin->second.front();

    for (size_t i = 1; i < res.size() - 1; ++i) {
      for (auto adjacent : adjacents[current]) {
        if (adjacent == prev) continue;
        res[i] = prev = current;
        current = adjacent;
        break;
      }
    }

    res[res.size() - 1] = current;

    return res;
  }
};
