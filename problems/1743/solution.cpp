// The solution can be done as follows:
// - Convert a vector of pairs to a hash map for easy access to adjacent values.
// - Find the beginning (or the end) of the array's value. This can be done by searching for a value in the hash map that has only one adjacent value.
// - Recursively construct the array by putting adjacent values starting from the beginning value.

class Solution {
 public:
  vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    // Convert to a hash map. Both values of the pair will be associated with different keys.
    unordered_map<int, list<int>> adjacents;
    for (const auto& pair : adjacentPairs) {
      adjacents[pair[0]].push_back(pair[1]);
      adjacents[pair[1]].push_back(pair[0]);
    }

    // Find the beginning (or the end) of the array's value.
    const auto begin = find_if(adjacents.begin(), adjacents.end(), [](const auto& pair) {
      return pair.second.size() == 1;
    });

    // Construct the array starting with the beginning value.
    vector<int> res(adjacentPairs.size() + 1);
    res[0] = begin->first;

    // Repeatedly add adjacent values starting from the beginning value.
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

    // Add the last value.
    res[res.size() - 1] = current;

    return res;
  }
};
