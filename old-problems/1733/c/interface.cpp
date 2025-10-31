#include <vector>

extern "C" {
int minimumTeachings(
    int n, int** languages, int languagesSize, int* languagesColSize,
    int** friendships, int friendshipsSize, int* friendshipsColSize);
}

int solution_c(
    int n, std::vector<std::vector<int>> languages,
    std::vector<std::vector<int>> friendships) {
  std::vector<int*> languagesDatas(languages.size());
  std::vector<int> languagesSizes(languages.size());
  for (std::size_t i{0}; i < languages.size(); ++i) {
    languagesDatas[i] = languages[i].data();
    languagesSizes[i] = languages[i].size();
  }

  std::vector<int*> friendshipsDatas(friendships.size());
  std::vector<int> friendshipsSizes(friendships.size());
  for (std::size_t i{0}; i < friendships.size(); ++i) {
    friendshipsDatas[i] = friendships[i].data();
    friendshipsSizes[i] = friendships[i].size();
  }

  return minimumTeachings(
      n, languagesDatas.data(), languages.size(), languagesSizes.data(),
      friendshipsDatas.data(), friendships.size(), friendshipsSizes.data());
}
