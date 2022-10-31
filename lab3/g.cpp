#include <math.h>
// #include <format.h>
#include <iostream>

int main(int argc, char** argv) {
  // std::ios::sync_with_stdio(0);
  // std::cin.tie(0);
  // std::cout.tie(0);

  int n = 0;
  double A = 0;
  std::cin >> n >> A;
  // A *= 100;

  double array[n];
  array[0] = A;

  double r = A * 1000;
  double l = 0;

  while (r - l > 0.000001) {
    array[1] = (r + l) / 2;
    bool above = true;
    for (int i = 2; i < n; i++) {
      array[i] = 2 * array[i - 1] - array[i - 2] + 2;
      if (array[i] < 0) {
        above = false;
        break;
      }
    }

    if (above) {
      r = array[1];
    } else {
      l = array[1];
    }
  }
  array[1] = r;
  for (int i = 2; i < n; i++) {
    array[i] = 2.0 * array[i - 1] - array[i - 2] + 2;
    // std::cout << array[i] << "-" << i << "\n";
  }
  // array[n-1] = int(array[n-1]);
  printf("%.2f\n", array[n-1]);//array[n - 1]*100/ 100.0 << "\n";

  // for (int i = 1; i < n - 1; i++) {
  //   // if (array[i] != ((array[i + 1] + array[i - 1]) / 2 - 1))
  //     std::cout << array[i] << " " << ((array[i + 1] + array[i - 1]) / 2 - 1)
  //               << " => "
  //               << (array[i] == ((array[i + 1] + array[i - 1]) / 2 - 1))
  //               << "\n";
  // }
}