// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp
#include <iostream>
#include <string>
using namespace std;

const int MAX_V = 100000;
const int MAX_D = 10000;
const int MAX_E = 500000;
const int INF = 999999999;
int V, E, R;

struct edge {
  int from, to, cost;
};
edge es[MAX_E];
int d[MAX_V];

void solve() {
  for (int i = 0; i < V; i++) {
    d[i] = INF;
  }
  d[R] = 0; // 初期化
  while (true) {
    bool update = false;
    for (int i = 0; i < E; i++) {
      edge e = es[i];
      if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;
        update = true;
      }
    }
    if (!update) {
      break;
    }
  }
  for (int i = 0; i < V; i++) {
    cout << ((d[i] == INF) ? "INF" : to_string(d[i])) << endl;
  }
}

int main() {
  cin >> V >> E >> R;
  cin.ignore();
  for (int i = 0; i < E; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    cin.ignore();
    es[i] = edge{from, to, cost};
  }
  solve();
}
