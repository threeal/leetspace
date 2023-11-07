class Solution {
 public:
  int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    int n = min(dist.size(), speed.size());
    for (int i = 0; i < n; ++i) {
      dist[i] = dist[i] / speed[i] + (dist[i] % speed[i] > 0 ? 1 : 0);
    }

    sort(dist.begin(), dist.end());

    int kills = 0;
    for (const auto val : dist) {
      if (kills + 1 > val) break;
      ++kills;
    }

    return kills;
  }
};
