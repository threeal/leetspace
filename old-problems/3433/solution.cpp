#include <algorithm>
#include <queue>
#include <string>
#include <string_view>
#include <vector>

struct Event {
  int timestamp;
  bool is_message;
  std::string_view content;
};

class Solution {
 public:
  std::vector<int> countMentions(
      int numberOfUsers, std::vector<std::vector<std::string>>& events) {
    std::vector<Event> parsedEvents(events.size());
    for (std::size_t i{0}; i < events.size(); ++i) {
      parsedEvents[i].timestamp = std::stoi(events[i][1]);
      parsedEvents[i].is_message = events[i][0][0] == 'M';
      parsedEvents[i].content = events[i][2];
    }

    std::sort(
        parsedEvents.begin(), parsedEvents.end(),
        [&](const auto& a, const auto& b) {
          return a.timestamp == b.timestamp
              ? b.is_message
              : a.timestamp < b.timestamp;
        });

    std::vector<int> mentions(numberOfUsers, 0);

    std::vector<bool> onlineUsers(numberOfUsers, true);
    std::priority_queue<std::array<int, 2>> offlineUsers{};

    for (const auto& event : parsedEvents) {
      while (!offlineUsers.empty() &&
             -offlineUsers.top()[0] <= event.timestamp) {
        onlineUsers[offlineUsers.top()[1]] = true;
        offlineUsers.pop();
      }

      if (event.is_message) {
        switch (event.content[0]) {
          case 'A':
            for (int i{0}; i < numberOfUsers; ++i) ++mentions[i];
            break;

          case 'H':
            for (int i{0}; i < numberOfUsers; ++i) {
              if (onlineUsers[i]) ++mentions[i];
            }
            break;

          default:
            for (std::size_t i{2}; i < event.content.size(); i += 3) {
              int userId{0};
              while (i < event.content.size() && event.content[i] != ' ') {
                userId = userId * 10 + event.content[i] - '0';
                ++i;
              }
              ++mentions[userId];
            }
        }
      } else {
        int userId{0};
        for (std::size_t i{0}; i < event.content.size(); ++i) {
          userId = userId * 10 + event.content[i] - '0';
        }
        onlineUsers[userId] = false;
        offlineUsers.push({-event.timestamp - 60, userId});
      }
    }

    return mentions;
  }
};
