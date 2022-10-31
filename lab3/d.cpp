#include <math.h>
#include <string.h>
#include <sstream>
#include <iostream>

const int64_t MAX_INT = pow(2, 31);

struct Node {
  int64_t value = MAX_INT;
  Node* prev = nullptr;
};

struct Stack {
  Node* tail = nullptr;

  void push(int64_t new_value) {
    Node* new_el_ptr = new Node({new_value});
    if (tail != nullptr) {
      new_el_ptr->prev = tail;
    }
    tail = new_el_ptr;
  }

  int64_t pop() {
    Node* to_del = tail;
    int64_t result = tail->value;
    tail = tail->prev;
    to_del->prev = nullptr;
    delete to_del;
    return result;
  }

  bool is_empty() { return tail == nullptr; }
};

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  Stack my_stack = Stack();
  std::string line = "";
  std::getline(std::cin, line);

  std::string now = "";

  std::istringstream split(line);
  while (std::getline(split, now, ' ')) {
    if (!('0' <= now[0] && now[0] <= '9') && now.size() == 1) {
      int64_t fir = my_stack.pop();
      int64_t sec = my_stack.pop();
      if (now == "+") {
        my_stack.push(fir + sec);
      } else if (now == "-") {
        my_stack.push(sec - fir);
      } else if (now == "*") {
        my_stack.push(fir * sec);
      }
    } else {
      if (now[0] == '-') {
        my_stack.push(-1 * atoi(&(now[1])));
      } else {
        my_stack.push(atoi(&(now[0])));
      }
    }
  }
  std::cout << my_stack.pop() << "\n";
}