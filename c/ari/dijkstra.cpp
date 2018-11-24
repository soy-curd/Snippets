// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp
#include <iostream>
#include <string>
using namespace std;

const int MAX_V = 100000;
const int MAX_D = 10000;
const int MAX_E = 500000;
const int INF = 999999999;
int V, E, R;

int cost[MAX_V][MAX_V];
int d[MAX_V];
bool used[MAX_V];

void solve() {
  fill(d, d + V, INF);
  fill(used, used + V, false);
  d[R] = 0; // 初期化

  while (true) {
    int v = -1;
    // まだ使われていない頂点のうち距離が最小のもの
    for (int u = 0; u < V; u++) {
      if (!used[u] && (v == -1 || d[u] < d[v])) {
        v = u;
      }
    }
    if (v == -1) {
      break;
    }
    used[v] = true;

    for (int u = 0; u < V; u++) {
      d[u] = min(d[u], d[v] + cost[v][u]);
    }
  }

  for (int i = 0; i < V; i++) {
    cout << ((d[i] == INF) ? "INF" : to_string(d[i])) << endl;
  }
}

int main() {
  cin >> V >> E >> R;
  cin.ignore();
  fill(cost[0], cost[V], INF);
  for (int i = 0; i < E; i++) {
    int from, to, c;
    cin >> from >> to >> c;
    cin.ignore();
    cost[from][to] = c;
    cost[to][from] = c;
  }
  solve();
}
