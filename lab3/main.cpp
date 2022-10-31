#include <iostream>

struct numb_in_array {
  int first_income = -2;
  int last_income = -2;
};

std::ostream& operator<<(std::ostream& stream, const numb_in_array& number) {
  stream << number.first_income + 1 << " " << number.last_income + 1 << "\n";
  return stream;
}

numb_in_array bin_search(int array[], int n, int x);

int main() {
  int n = 0;
  std::cin >> n;

  int array[n];
  for (int i = 0; i < n; i++) {
    std::cin >> array[i];
  }

  int m = 0;
  std::cin >> m;
  for (int i = 0; i < m; i++) {
    int find_now = 0;
    std::cin >> find_now;
    std::cout << bin_search(array, n, find_now);
  }

  return 0;
}

numb_in_array bin_search(int array[], int n, int x) {
  int left = -1;
  int right = n;
  int mid;
  numb_in_array res;

  while (right - left > 1) {
    mid = (right + left) / 2;
    if (array[mid] < x) {
      left = mid;
    } else {
      right = mid;
    }
  }
  if(array[right] == x){
    res.first_income = right;
    left = right;
    right = n;
    while (right - left > 1) {
      mid = (right + left) / 2;
      if (array[mid] <= x) {
        left = mid;
      } else {
        right = mid;
      }
    }
    res.last_income = left;
  }else{
    res.first_income = -1;
    res.last_income = -1;
  }
  
  return res;
}
