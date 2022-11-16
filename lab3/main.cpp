#include <iostream>

int main() {
  int n = 0, m = 0;
  std::cin >> n >> m;

  int64_t up[n + 1];
  int64_t right[n + 1];

  for (int i = 0; i < n + 1; i++) {
    up[i] = 0;
    right[i] = 0;
  }
  char command;
  int64_t step;
  for (int i = 1; i <= n; i++) {
    std::cin >> command >> step;
    right[i] = right[i - 1];
    up[i] = up[i - 1];
    switch (command) {
      case 'R':
        right[i] += step;
        break;
      case 'L':
        right[i] -= step;
        break;
      case 'U':
        up[i] += step;
        break;
      case 'D':
        up[i] -= step;
        break;
      default:
        break;
    }
  }

  int a = 0;
  int b = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> a >> b;
    if (right[a] - right[b] < 0) {
      std::cout << right[b] - right[a] << " ";
    } else {
      std::cout << right[a] - right[b] << " ";
    }

    if (up[a] - up[b] < 0) {
      std::cout << up[b] - up[a] << "\n";
    } else {
      std::cout << up[a] - up[b] << "\n";
    }
  }

  return 0;
}
