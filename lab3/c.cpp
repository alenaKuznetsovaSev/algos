#include <iostream>
#include <string.h>
#include <math.h>

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
  // std::ios::sync_with_stdio(0);
  // std::cin.tie(0);
  // std::cout.tie(0);

  std::string line;
  while(std::cin >> line){
    Stack my_stack = Stack();
    bool correct_seq = true;
    for (int i = 0; i < line.size(); i++){
      if (line[i] == '(' || line[i] == '['){
        my_stack.push(line[i]);
      }else{
        if (my_stack.is_empty()) {
          correct_seq = false;
          break;
        }else{
          int now_breaker = my_stack.pop();
          if (now_breaker == '(' && line[i] == ')') {
            continue;
          }else if (now_breaker == '[' && line[i] == ']') {
            continue;
          }else{
            correct_seq = false;
            break;
          }
        }
      }
    }
    if (correct_seq && my_stack.is_empty())
      std::cout << "YES\n";
    else
      std::cout << "NO\n";
  }  
}

