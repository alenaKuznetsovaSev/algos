#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  int n, k;
  std::cin >> n >> k;
  long double array[n];
  for (int i = 0; i < n; i++) {
    std::cin >> array[i];
  }


  // if(k == 0);
  
  long long l = 0;
  long long r = 2 * 1000 ;//* 1000 * 1000;
  long long mid;
  int k_now;
  while (r - l > 0.001) {
    mid = (r + l) / 2;
    k_now = 0;
    for (int i = 0; i < n; i++) {
      if (array[i] > mid) {
        k_now += array[i]/mid;
      }
      if (k_now > k) break;
    }
    if (k_now > k) {
      l = mid;
    } else {
      r = mid;
    }
  }
  long long result = r;
  // if(r - result > 0.01){
  //   result++;
  // }
  std::cout << result;
  return 0;
}
