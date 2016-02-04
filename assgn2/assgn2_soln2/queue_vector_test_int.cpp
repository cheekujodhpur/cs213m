#include "queue_vector.hpp"
#include "queue_vector.cpp"
#include <iostream>


using namespace std;

int main() {
  queue_vector<int> *q = new queue_vector<int>();

  int n_ops;
  cin >> n_ops;

  while(n_ops) {
    n_ops--;

    char op;
    cin >> op;

    // push_back
    if (op == 'p') {
      int arg;
      cin >> arg;
      q->push_back(arg);
    }
    // front
    else if (op == 'f') {
      int elem;
      q->front(&elem);
      cout << elem << endl;
    }
    // pop_front
    else if (op == 'o') {
      q->pop_front();
    }
    // size
    else if (op == 's') {
      cout << q->size() << endl;
    }
    // dump
    else if (op == 'd') {
      queue_vector<int> to_print = *q;
      int elem;
      while (to_print.size()) {
        to_print.front(&elem);
        cout << elem << ' ';
        to_print.pop_front();
      }
      cout << '_' << endl;
    }
  }
}
