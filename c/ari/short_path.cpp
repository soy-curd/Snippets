#include <algorithm>
#include <cstdio>
using namespace std;
const int MAX_N = 100;

int main() {
  // int n = 5;
  // int a[MAX_N] = {2, 3, 4, 5, 10};
  int n = 4;
  int a[MAX_N] = {4, 5, 10, 20};
  int *end = a + sizeof(a) / sizeof(a[0]);
  int ans = 0;
  sort(a, std::end(a), [](int x, int y) -> int { return (x > y); });
  int ans_1 = 0;
  int ans_2 = 0;
  int ans_3 = 0;
  for (int i = 0; i < n - 2; i++) {
    if (a[i] < a[i + 1] + a[i + 2]) {
      ans = a[i] + a[i + 1] + a[i + 2];
      break;
    }
  }

  printf("%d\n", ans);
}
