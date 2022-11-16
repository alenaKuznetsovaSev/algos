#include <iostream>

void swift_down(int* array, int n, int current);
void heap_sort(int* array, int n);

int main(int argc, char** argv) {
  int n;
  std::cin >> n;
  int array[n];
  for (int i = 0; i < n; i++) {
    std::cin >> array[i];
  }

  heap_sort(array, n);
  for (int i = 0; i < n; i++) {
    std::cout << array[i] << " ";
  }
  return 0;
}

void heap_sort(int* array, int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    swift_down(array, n, i);
  }

  for (int i = n - 1; i >= 0; i--) {
    std::swap(array[0], array[i]);
    swift_down(array, i, 0);
  }
}

void swift_down(int* array, int n, int current) {
  int l = 2 * current + 1;
  int r = 2 * current + 2;
  int biggest = current;
  if (l < n && array[biggest] < array[l]) {
    biggest = l;
  }
  if (r < n && array[biggest] < array[r]) {
    biggest = r;
  }

  if(biggest != current){
    std::swap(array[biggest], array[current]);
    swift_down(array, n, biggest);
  }
}