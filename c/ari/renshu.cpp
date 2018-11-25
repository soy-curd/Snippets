
// #include <iostream>
// using namespace std;

// struct node {
//   int val;
//   node *left;
//   node *right;
// };

// node *insert(node *p, int x) {
//   if (p == NULL) {
//     auto q = new node();
//     q->val = x;
//     return q;
//   }
//   if (p->val < x) {
//     p->right = insert(p->right, x);
//   } else {
//     p->left = insert(p->left, x);
//   }
//   return p;
// }

// bool find(node *p, int x) {
//   if (p == NULL) {
//     return false;
//   }
//   if (p->val == x) {
//     return true;
//   }
//   if (p->val < x) {
//     return find(p->right, x);
//   } else {
//     return find(p->left, x);
//   }
// }

// int main() {
//   node *p;
//   p = insert(p, 1);
//   p = insert(p, 100);
//   p = insert(p, 3);
//   p = insert(p, 4);
//   cout << find(p, 3) << endl;
//   cout << find(p, 4) << endl;
//   cout << find(p, 5) << endl;
// }

#include <iostream>
using namespace std;

const int MAX_N = 1 << 16;
int heap[MAX_N];
int sz = 0;

void push(int x) {
  sz++;
  heap[sz - 1] = x;
  int current = sz - 1;
  while (current != 0) {
    int parent = (current - 1) / 2;
    if (heap[parent] < x) {
      return;
    } else {
      int buf = heap[parent];
      heap[parent] = x;
      heap[current] = buf;
    }
    current = parent;
  }
}

int pop() {
  if (sz == 0) {
    return -1;
  }
  sz--;
  int last = heap[sz];
  int value = heap[0];
  heap[0] = last;
  int current = 0;
  while (true) {
    int buf;
    int left = 2 * current + 1;
    int right = 2 * current + 2;
    if (sz <= left) {
      break;
    }
    if (sz > right && heap[right] < heap[left]) {
      left = right;
    }
    if (heap[current] > (heap[left])) {
      buf = heap[current];
      heap[current] = heap[left];
      heap[left] = buf;
    }
    current = left;
  }
  return value;
}

void check_heap() {
  for (int i = 0; i < sz; i++) {
    cout << heap[i] << ",";
  }
  cout << endl;
}

int main() {
  push(4);
  push(3);
  push(5);
  push(3);
  push(100);
  cout << pop() << endl;
  cout << pop() << endl;
  cout << pop() << endl;
  cout << pop() << endl;
  cout << pop() << endl;
}
