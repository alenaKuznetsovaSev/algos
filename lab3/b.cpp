#include <math.h>
#include <iostream>

#define MAX_INT int(pow(10, 9) + 1)

struct Node {
  int value = MAX_INT;
  Node* prev = nullptr;
};

struct Stack {
  Node* tail = nullptr;

  void push(int new_value) {
    Node* new_el_ptr = new Node({new_value});
    if (tail != nullptr) {
      new_el_ptr->prev = tail;
    }
    tail = new_el_ptr;
  }

  int pop() {
    Node* to_del = tail;
    int result = tail->value;
    tail = tail->prev;
    to_del->prev = nullptr;
    delete to_del;
    return result;
  }
  
  bool is_empty(){
      return tail == nullptr;
  }
};

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int n;
  std::cin >> n;
  Stack my_queue;
  for (int i = 0; i < n; i++) {
    char operation;
    std::cin >> operation;
    if (operation == '+') {
      int new_value;
      std::cin >> new_value;
      my_queue.push(new_value);
    } else {
      std::cout << my_queue.pop() << "\n";
    }
  }
}