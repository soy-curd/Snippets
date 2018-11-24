// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp
#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;
typedef pair<int, int> P; // firstは最短距離、secondeは頂点の番号

const int MAX_V = 100000;
const int MAX_D = 10000;
const int MAX_E = 500000;
const int INF = 999999999;
int V, E, R;
struct edge
{
  int to, cost;
};

vector<edge> G[MAX_V];
int d[MAX_V];

void solve()
{
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d, d + V, INF);
  d[R] = 0;
  que.push(P(0, R));
  while (!que.empty())
  {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first)
    {
      continue;
    }

    for (int i = 0; i < G[v].size(); i++)
    {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost)
      {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
  for (int i = 0; i < V; i++)
  {
    cout << ((d[i] == INF) ? "INF" : to_string(d[i])) << endl;
  }
}

int main()
{
  cin >> V >> E >> R;
  cin.ignore();
  for (int i = 0; i < E; i++)
  {
    int from, to, c;
    cin >> from >> to >> c;
    cin.ignore();
    G[from].push_back(edge{to, c});
  }
  solve();
}
