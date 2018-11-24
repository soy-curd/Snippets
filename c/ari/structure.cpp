#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;
const int MAX_N = 100;

int fact(int n)
{
  if (n == 0)
  {
    return 1;
  }
  return n * fact(n - 1);
}
int memo[MAX_N + 1];

int fib(int n)
{
  if (n == 0 || n == 1)
  {
    return 1;
  }
  if (memo[n])
  {
    return memo[n];
  }

  memo[n] = fib(n - 1) + fib(n - 2);

  return memo[n];
}

void stack_check()
{
  std::stack<int> s;
  s.push(1);
  s.push(2);
  printf("%d\n", s.top());
  s.pop();
  printf("%d\n", s.top());
  s.pop();
}

void queue_check()
{
  queue<int> que;
  que.push(1);
  que.push(2);
  que.push(3);
  printf("%d\n", que.front());
  que.pop();
  printf("%d\n", que.front());
  que.pop();
  printf("%d\n", que.front());
  que.pop();
}

int a[MAX_N];
int n, k;

// 部分和問題に深さ優先探索を用いる例
// iまででsumを作って、残りi以降を調べる
bool dfs(int i, int sum)
{
  if (i == n)
  {
    return sum == k;
  }
  if (dfs(i + 1, sum))
  {
    return true;
  }

  if (dfs(i + 1, sum + a[i]))
  {
    return true;
  }

  return false;
}

// bool solve()
// {
//   n = 4;
//   a[0] = 1;
//   a[1] = 2;
//   a[2] = 4;
//   a[3] = 7;
//   k = 15;
//   return dfs(0, 0);
// }

const int N = 10;
const int M = 12;

int mizu[N][M + 1];
bool used[MAX_N];
int perm[MAX_N];

// n!通り生成
void permutation1(int pos, int n)
{
  printf("pos: %d, n: %d\n", pos, n);
  if (pos == n)
  {
    return;
  }
  for (int i = 0; i < n; i++)
  {
    if (!used[i])
    {
      perm[pos] = i;
      used[i] = true;
      permutation1(pos + 1, n);

      used[i] = false;
    }
    for (int j = 0; j < 3; j++)
    {
      printf("%d\n", perm[i]);
    }
  }
  return;
}

#include <algorithm>
int perm2[MAX_N];
void permutation2(int n)
{
  for (int i = 0; i < n; i++)
  {
    perm2[i] = i;
  }
  do
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d", perm2[j]);
    }
    printf("\n");
  } while (next_permutation(perm2, perm2 + n));
}

void solve()
{
  permutation2(3);
  printf("%p\n", perm2);
  printf("%p\n", perm2 + 3);
}

int main() { solve(); }
