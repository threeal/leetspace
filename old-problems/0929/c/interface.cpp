#include <string>
#include <vector>

extern "C" {
int numUniqueEmails(char** emails, int emailsSize);
}

int solution_c(std::vector<std::string> emails) {
  std::vector<char*> emailsDatas(emails.size());
  for (int i = emails.size() - 1; i >= 0; --i) {
    emailsDatas[i] = emails[i].data();
  }

  return numUniqueEmails(emailsDatas.data(), emailsDatas.size());
}
