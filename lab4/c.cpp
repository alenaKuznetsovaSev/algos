#include <string.h>

#include <iostream>

struct number {
  int value = 1000*1000*1000+1;
  int priority = 1000*1000+1;
};

int operator<(number& lhs, number& rhs) {
  if (lhs.value == rhs.value) return lhs.priority < rhs.priority;
  return lhs.value < rhs.value;
}
int operator>(number& lhs, number& rhs) {
  return rhs < lhs;
}
int operator==(number& lhs, number& rhs) {
  return rhs.priority ==  lhs.priority && rhs.value == lhs.value;
}


void swift_down(number* array, int n, int current);
void swift_up(number* array, int current);
void heap_sort(number* array, int n);

int main(int argc, char** argv) {
  int n = 0;
  number array[10];//00 * 1000 + 1];
  std::string command;
  int now_adress;
  int new_val;
  for (int i = 0; std::cin >> command; i++) {
    
     if (command == "push") {
      std::cin >> array[n].value;
      array[n].priority = i + 1;
      n++;
      swift_up(array, n - 1);
    } else if (command == "extract-min") {
      if (n > 0) {
        std::cout << array[0].value << "\n";
        std::swap(array[0], array[n-1]);
        n--;
        swift_down(array, 0, n);
      } else {
        std::cout << "*\n";
      }
    } else if (command == "decrease-key") {
      std::cin >> now_adress >> new_val;
      for (int j = 0; j < n; j++) {
        if (array[j].priority == now_adress) {
          if (array[j].value < new_val) {
            array[j].value = new_val;
            swift_down(array, j, n);
          } else if(array[j].value > new_val){
            array[j].value = new_val;
            swift_up(array, j);
          }
          break;
        }
      }
    }
  }
  return 0;
}


void heap_sort(number* array, int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    swift_down(array, n, i);
  }

  for (int i = n - 1; i >= 0; i--) {
    std::swap(array[0], array[i]);
    swift_down(array, i, 0);
  }
}

void swift_down(number* array, int n, int current) {
  int l = 2 * current + 1;
  int r = 2 * current + 2;
  int biggest = current;
  if (l < n && array[biggest] < array[l]) {
    biggest = l;
  }
  if (r < n && array[biggest] < array[r]) {
    biggest = r;
  }

  if (biggest != current) {
    std::swap(array[biggest], array[current]);
    swift_down(array, n, biggest);
  }
}

void swift_up(number* array, int current) {
  int parent = (current -1)/2;

  if (parent >= 0 && array[current] < array[parent]) {
    std::swap(array[current], array[parent]);
    swift_up(array, parent);
  }
}