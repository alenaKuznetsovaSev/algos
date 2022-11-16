#include <math.h>

#include <iostream>

int main(int argc, char** argv) {

  int n;
  std::cin >> n;
  int array[n];
  std::cin >> array[0];
  for (int i = 1; i < n; i++) {
    std::cin >> array[i];
    if(array[(i-1)/2] > array[i]){
      std::cout << "NO\n";
      return 0;
    }
  }
  std::cout <<"YES\n";
  return 0;
}