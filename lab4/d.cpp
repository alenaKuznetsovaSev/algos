#include <math.h>
#include <string.h>

#include <deque>
#include <iostream>

int main(int argc, char** argv) {
  int n = 0;
  int m = 0;
  int k = 0;
  std::cin >> n >> m >> k;

  std::deque<std::string> dict[26];
  std::string now;
  for (int i = 0; i < n; i++) {
    std::cin >> now;
    dict[now[m - 1] - 'a'].push_back(now);
  }

  for (int i = 1; i <= k && i <= m; i++) {
    std::deque<std::string> tmp[26];
    for (int j = 0; j < 26; j++) {
      while (!dict[j].empty()) {
        now = dict[j].front();
        dict[j].pop_front();
        int adr = (now[m-i] - 'a');
        tmp[adr].push_back(now);
      }
    }
    for (int j = 0; j < 26; j++) {
      dict[j] = tmp[j];
    }
  }

  for (int j = 0; j < 26; j++) {
    while (!dict[j].empty()) {
      std::cout << dict[j].front() << "\n";
      dict[j].pop_front();
    }
  }
  return 0;
}