class Solution {
 public:
  vector<string> buildArray(vector<int>& target, int n) {
    vector<string> cmds;

    auto ti = target.begin();
    for (int i = 1; i <= n && ti != target.end(); ++i) {
      if (*ti == i) {
        cmds.push_back("Push");
        ++ti;
      } else {
        cmds.push_back("Push");
        cmds.push_back("Pop");
      }
    }

    return cmds;
  }
};
