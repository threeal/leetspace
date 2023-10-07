class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    map<int, int, greater<int>> counts;
    for (const auto num : nums) {
      ++counts[num];
    }

    vector<vector<int>> result;
    const auto counts_end = counts.end();
    for (auto ai = counts.begin(); ai != counts_end; ++ai) {
      const auto a = ai->first;
      if (a <= 0) break;

      auto bi = ai;
      if (bi->second <= 1) ++bi;
      for (; bi != counts_end; ++bi) {
        const auto b = bi->first;
        if (-b - a > b) break;
        const auto ci = counts.find(-b - a);
        if (ci == counts_end) continue;
        if (ci->first == b && ci->second < 2) continue;
        result.push_back({ci->first, b, a});
      }
    }

    if (counts[0] >= 3) {
      result.push_back({0, 0, 0});
    }

    return result;
  }
};
