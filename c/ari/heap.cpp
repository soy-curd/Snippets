
#include <cstdio>
using namespace std;

const int MAX_N = 1000000;

int heap[MAX_N], sz = 0;

void push(int x)
{
  // 自分のノード番号
  int i = sz++;
  while (i > 0)
  {
    int p = (i - 1) / 2; // 親

    if (heap[p] < x)
    {
      break;
    }
    heap[i] = heap[p];
    i = p;
    heap[i] = x;
  }
}

int pop()
{
  int ret = heap[0];
  int x = heap[--sz];

  int i = 0;
  while (i * 2 + 1 < sz)
  {
    int a = i * 2 + 1;
    int b = i * 2 + 2;
    if (b < sz && heap[b] < heap[a])
    {
      a = b;
    }

    if (heap[a] >= x)
    {
      break;
    }

    heap[i] = heap[a];
    i = a;
  }

  heap[i] = x;

  return ret;
}

#include <queue>

void check_queue()
{
  priority_queue<int, vector<int>, greater<int>> pque;

  pque.push(3);
  pque.push(5);
  pque.push(1);

  while (!pque.empty())
  {
    printf("%d\n", pque.top());
    pque.pop();
  }
}

int N = 4;
int L = 25;
int P = 10;
int A[MAX_N] = {10, 14, 20, 21};
int B[MAX_N] = {10, 5, 2, 4};

void solve()
{
  priority_queue<int> pque;
  int ans = 0;
  int nokori = P;
  int now = 0;
  for (int i = 0; i < N; i++)
  {
    nokori -= A[i] - now;
    nokori += B[i];
    now += A[i];
    printf("%d\n", nokori);
    if (nokori < 0)
    {
      printf("%d\n", -1);
      return;
    }
    pque.push(B[i]);
  }
  L -= P;
  while (L > 0 && !pque.empty())
  {
    printf("%d\n", pque.top());
    L -= pque.top();
    ans += 1;
    pque.pop();
  }
  printf("%d\n", ans);
}

int main()
{
  printf("hoge\n");
  solve();
}