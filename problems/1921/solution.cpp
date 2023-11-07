class Solution {
 public:
  int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    int n = min(dist.size(), speed.size());
    int kills = 0;
    int damage = 0;
    while (damage == 0 && kills < n) {
      int nearest = 0;
      while (dist[nearest] < 0) ++nearest;
      dist[nearest] -= speed[nearest];
      if (dist[nearest] <= 0) ++damage;

      for (int i = nearest + 1; i < n; ++i) {
        if (dist[i] < 0) continue;
        dist[i] -= speed[i];
        if (dist[i] <= 0) ++damage;
        if (dist[i] < dist[nearest]) nearest = i;
      }

      if (dist[nearest] <= 0) --damage;
      dist[nearest] = -1;
      ++kills;
    }
    return kills;
  }
};
