#include <cstdio>

const int MAX_N = 50;

int main() {
  int n, m, k[MAX_N];
  n = 3;
  m = 9;
  k[0] = 1;
  k[1] = 3;
  k[2] = 5;

  bool f = false;
  for (int a = 0; a < n && !f; a++) {
    for (int b = 0; b < n && !f; b++) {
      for (int c = 0; c < n && !f; c++) {
        for (int d = 0; d < n && !f; d++) {
          if (k[a] + k[b] + k[c] + k[d] == m) {
            f = true;
          }
        }
      }
    }
  }

  if (f) {
    puts("ok");
  } else {
    puts("no");
  }
  return 0;
}