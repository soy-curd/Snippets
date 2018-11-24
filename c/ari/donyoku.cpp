#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;
const int MAX_N = 10000;

// const int V[6] = {1, 5, 10, 50, 100, 500};

// void kouka() {
//   int C[6] = {3, 2, 1, 3, 0, 2};
//   int A = 620;
//   int ans = 0;
//   for (int i = 5; i >= 0; i--) {
//     int t = min(A / V[i], C[i]);
//     A -= t * V[i];
//     ans += t;
//   }

//   printf("%d\n", ans);
// }

// int N = 5;
// pair<int, int> itv[MAX_N];
// int S[MAX_N] = {1, 2, 4, 6, 8};
// int T[MAX_N] = {3, 5, 7, 9, 10};

// void bou()
// {
//   for (int i = 0; i < N; i++)
//   {
//     itv[i].first = T[i];
//     itv[i].second = S[i];
//   }

//   sort(itv, itv + N);
//   for (int i = 0; i < N; i++)
//   {
//     printf("%d, %d\n", itv[i].first, itv[i].second);
//   }

//   int ans = 0, t = 0; // tは最後に選んだ仕事の終了時間
//   for (int i = 0; i < N; i++)
//   {
//     if (t < itv[i].second)
//     {
//       ans++;
//       t = itv[i].first;
//     }
//   }
//   printf("%d\n", ans);
// }

#include <string>

// const int N = 6;
// string moji = "ACDBCB";
// string reversed;
// string buf;

// void solve() {
//   reversed = moji;
//   reverse(reversed.begin(), reversed.end());

//   for (int i = 0; i < N; i++) {
//     printf("%s\n", moji.c_str());
//     printf("%s\n", reversed.c_str());

//     if (moji < reversed) {
//       buf += moji[0];
//       moji.erase(moji.begin());
//     } else {
//       buf += reversed[0];
//       reversed.erase(reversed.begin());
//     }
//   }

//   printf("%s\n", buf.c_str());
// }

// int N = 6;
// int R = 10;
// int X[MAX_N] = {1, 7, 15, 20, 30, 50};

// // R以内の一番右につける

// int findRight(int now)
// {
//   if (now == N)
//   {
//     return now;
//   }
//   int n = X[now];

//   for (int i = now + 1; i < N; i++)
//   {
//     if (n < X[i] - R)
//     {
//       return i - 1;
//     }
//   }
//   return now;
// }

// void solve()
// {
//   sort(X, X + N);
//   int ans = 0;
//   int rightIndex = 0; // 一番右のターゲット
//   int left = X[0];
//   for (int i = 1; i < N; i++)
//   {
//     if (left < X[i] - R)
//     {
//       ans += 1;
//       i = findRight(i);
//     }
//   }
//   printf("%d\n", ans);
// }

// int N = 3;
// int L[MAX_N] = {8, 5, 8};

// void solve()
// {
//   sort(L, L + N);
//   reverse(L, L + N);
//   int length = 0;
//   for (int i = 0; i < N; i++)
//   {
//     length += L[i];
//   }
//   int ans = 0;
//   for (int i = 0; i < N - 1; i++)
//   {
//     ans += length;
//     length -= L[i];
//     printf("%d, %d\n", ans, L[i]);
//   }
//   printf("%d\n", ans);
// }

#include <utility>

template <class Array> void print(Array &ar) {
  for (auto x : ar) {
    printf("%d", x);
  }
  printf("\n");
}

// typedef long long ll;
// int N = 3;
// int L[MAX_N] = {8, 5, 8};

// void solve()
// {
//   // sort(L, L + N);
//   ll ans = 0;
//   while (N > 1)
//   {
//     int mii1 = 0, mii2 = 1;
//     if (L[mii1] > L[mii2])
//     {
//       swap(mii1, mii2); // 常にmii1 < mii2を保つ
//     }
//     for (int i = 2; i < N; i++)
//     {
//       if (L[i] < L[mii1])
//       {
//         // 最小値更新
//         mii2 = mii1;
//         mii1 = i;
//       }
//       else if (L[i] < L[mii2])
//       {
//         // 最小値から二番目の値更新
//         mii2 = i;
//       }
//     }
//     int t = L[mii1] + L[mii2];
//     ans += t;
//     if (mii1 == N - 1)
//     {
//       swap(mii1, mii2);
//     }
//     L[mii1] = t;
//     L[mii2] = L[N - 1];
//     N--;
//   }
//   printf("%lld\n", ans);
// }

// int N = 4;
// int W[MAX_N] = {2, 1, 3, 2};
// int V[MAX_N] = {3, 2, 4, 2};
// int w = 5;

// int dp[MAX_N + 1][MAX_N + 1]; // メモ化テーブル

// // i番目の品物から重さの総和がj以下となるように選ぶ
// int rec(int i, int j)
// {
//   if (dp[i][j] > 0)
//   {
//     return dp[i][j];
//   }
//   int res = 0;

//   if (i == N)
//   {
//     res = 0;
//   }
//   else if (j < W[i])
//   {
//     res = rec(i + 1, j);
//   }
//   else
//   {
//     res = max(rec(i + 1, j), rec(i + 1, j - W[i]) + V[i]);
//   }
//   dp[i][j] = res;
//   return res;
// }

// void solve()
// {
//   memset(dp, -1, sizeof(dp));
//   printf("%d\n", rec(0, w));
// }

int N = 4;
int M = 4;
string s = "abcd";
string t = "becd";
string ans = "";

// i以降とj以降の最大値
int rec(int i, int j, int len) {
  if (i >= N && j >= N) {
    return len;
  }

  if (s[i] == t[j]) {
    len += 1;
    ans += s[i];
    return rec(i + 1, j + 1, len);
  }
  if (i == N) {
    return rec(i, j + 1, len);
  } else if (j == N) {
    return rec(i + 1, j, len);
  }
  return max(rec(i + 1, j, len), rec(i, j + 1, len));
}

void solve() { printf("%d\n%s\n", rec(0, 0, 0), ans.c_str()); }

int main() { solve(); }
