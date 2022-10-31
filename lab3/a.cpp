#include <math.h>

#include <iostream>

#define MAX_INT int(pow(10, 9) + 1)

struct Node {
  int value = MAX_INT;
  Node* next = nullptr;
};

struct Queue {
  Node* head = nullptr;
  Node* tail = new Node();

  void push_back(int new_value) {
    Node* new_el_ptr = new Node({new_value});
    if (head == nullptr) {
      head = new_el_ptr;
    } else {
      tail->next = new_el_ptr;
    }
    tail = new_el_ptr;
  }

  int pop_first() {
    Node* to_del = head;
    int result = head->value;
    head = head->next;
    to_del->next = nullptr;
    delete to_del;
    return result;
  }
};

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int n;
  std::cin >> n;
  Queue my_queue;
  for (int i = 0; i < n; i++) {
    char operation;
    std::cin >> operation;
    if (operation == '+') {
      int new_value;
      std::cin >> new_value;
      my_queue.push_back(new_value);
    } else {
      std::cout << my_queue.pop_first() << "\n";
    }
  }
}