#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  int n, k;
  std::cin >> n >> k;
  int array[n];
  for (int i = 0; i < n; i++) {
    std::cin >> array[i];
  }

  uint64_t l = 0;
  uint64_t r = 2 * 1000ll * 1000 * 1000 * 1000 * 1000;
  uint64_t mid;
  uint64_t now_sum;
  int k_now;
  while (r - l > 1) {
    mid = (r + l) / 2;
    now_sum = 0;
    k_now = 0;
    for (int i = 0; i < n; i++) {
      if (now_sum + array[i] > mid) {
        now_sum = 0;
        k_now++;
      }
      if (k_now == k) break;
      now_sum += array[i];
    }
    if (k_now >= k) {
      l = mid;
    } else {
      r = mid;
    }
  }
  bool result[n];
  now_sum = array[0];
  result[0] = 0;
  k_now = 0;
  for (int i = 1; i < n; i++) {
    if (now_sum + array[i] > r) {
      now_sum = 0;
      result[i] = 1;
      k_now++;
    } else {
      result[i] = 0;
    }
    now_sum += array[i];
  }

  for (int t = 1; k_now < k - 1 && t < n; t++) {
    if (!result[t]) {
      result[t] = 1;
      k_now++;
    }
  }

  for (int i = 0; i < n; i++) {
    if (result[i]) {
      std::cout << i << " ";
    }
  }
  return 0;
}
