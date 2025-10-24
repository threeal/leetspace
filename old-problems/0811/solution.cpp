#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<std::string> subdomainVisits(
      std::vector<std::string>& cpdomains) {
    std::unordered_map<std::string_view, int> domainCounts{};
    for (const std::string& cpdomain : cpdomains) {
      int count{0};
      std::size_t i{0};
      while (cpdomain[i] != ' ') {
        count = count * 10 + cpdomain[i] - '0';
        ++i;
      }

      std::string_view subdomain(cpdomain.begin() + i + 1, cpdomain.end());

      const auto it = domainCounts.find(subdomain);
      if (it == domainCounts.end()) {
        domainCounts.emplace(subdomain, count);
      } else {
        it->second += count;
      }

      while (true) {
        const std::size_t pos{subdomain.find('.')};
        if (pos == std::string::npos) break;

        subdomain = subdomain.substr(pos + 1);

        const auto it = domainCounts.find(subdomain);
        if (it == domainCounts.end()) {
          domainCounts.emplace(subdomain, count);
        } else {
          it->second += count;
        }
      }
    }

    std::vector<std::string> output{};
    for (const auto& [subdomain, count] : domainCounts) {
      output.push_back(std::to_string(count).append(" ").append(subdomain));
    }

    return output;
  }
};
