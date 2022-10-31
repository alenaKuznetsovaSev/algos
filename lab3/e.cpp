#include <math.h>
#include <string.h>
#include <iostream>


#define now_type int

const now_type MAX_INT = pow(10, 9);


struct Node {
  now_type value = MAX_INT;
  now_type max = value;
  Node* prev = nullptr;
};

struct Stack {
  Node* tail = nullptr;

  void push(now_type new_value) {
    Node* new_el_ptr = new Node({new_value});
    if (tail != nullptr) {
      new_el_ptr->max = now_type(std::max(new_value, tail->max));
      new_el_ptr->prev = tail;
    }
    tail = new_el_ptr;
  }

  now_type pop() {
    Node* to_del = tail;
    now_type result = tail->value;
    tail = tail->prev;
    to_del->prev = nullptr;
    delete to_del;
    return result;
  }

  now_type get_max(){
    return tail->max;
  }

  bool is_empty() { return tail == nullptr; }
};

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  Stack my_stack = Stack();

  int n = 0;
  std::cin >> n;

  std::string now = "";
  now_type now_number = 0;
  for(int i = 0; i < n; i++){
    std::cin >> now;
    if (now == "+") {
      std::cin >> now_number;
      my_stack.push(now_number);
    }else if(now == "-"){
      my_stack.pop();
    }else if(now == "max"){
      std::cout << my_stack.get_max() << "\n"; 
    }
  }

}