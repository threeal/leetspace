#include <string>
#include <vector>

extern "C" {
char* rankTeams(char** votes, int votesSize);
}

std::string solution_c(std::vector<std::string> votes) {
  std::vector<char*> votesDatas(votes.size());
  for (int i = votes.size() - 1; i >= 0; --i) {
    votesDatas[i] = votes[i].data();
  }
  return rankTeams(votesDatas.data(), votesDatas.size());
}
