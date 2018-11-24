
#include <cstdio>
using namespace std;

const int MAX_N = 1000000;

struct node {
  int val;
  node *lch, *rch;
};

node *insert(node *p, int x) {
  if (p == NULL) {
    node *q = new node;
    q->val = x;
    q->lch = q->rch = NULL;
    return q;
  } else {
    if (x < p->val) {
      p->lch = insert(p->lch, x);
    } else {
      p->rch = insert(p->rch, x);
    }
    return p;
  }
}

bool find(node *p, int x) {
  if (p == NULL) {
    return false;
  } else if (p->val == x) {
    return true;
  } else if (x < p->val) {
    return find(p->lch, x);
  } else {
    return find(p->rch, x);
  }
}

node *remove(node *p, int x) {
  if (p == NULL) {
    return NULL;
  } else if (x < p->val) {
    p->lch = remove(p->lch, x);
  } else if (x > p->val) {
    p->rch = remove(p->rch, x);
  }
  // ここからはp->val == xの場合
  // 左の子がなければ右の子を上に上げる
  else if (p->lch == NULL) {
    node *q = p->rch;
    delete p;
    return q;
  }
  // 左の子の右の子がなければ左の子を上に上げる
  else if (p->lch->rch == NULL) {
    node *q = p->lch;
    q->rch = p->rch;
    delete p;
    return q;
  }
  // そのほかの場合は左の子の内で最も大きい値を上に上げる
  else {
    node *q;
    for (q = p->lch; q->rch->rch != NULL; q = q->rch)
      ;
    node *r = q->rch;
    q->rch = r->lch;
    r->lch = p->lch;
    r->rch = p->rch;
    delete p;
    return r;
  }
  return p;
}

#include <set>

void set_test() {
  printf("hoge\n");
  set<int> s;

  s.insert(1);
  s.insert(3);
  s.insert(5);

  set<int>::iterator ite;
  ;

  ite = s.find(1);
  if (ite == s.end()) {
    puts("not found");
  } else {
    puts("found");
  }
  s.erase(3);

  for (ite = s.begin(); ite != s.end(); ++ite) {
    printf("%d\n", *ite);
  }
}

#include <map>
#include <string>

void map_test() {
  map<int, const char *> m;
  map<int, const char *>::iterator ite;
  m[100] = "HUNDRED";
  m[1] = "ONE";
  m[2] = "SECOND";
  puts(m[100]);
  puts(m[1]);
  m.erase(100);

  for (ite = m.begin(); ite != m.end(); ++ite) {
    printf("%d %s\n", ite->first, ite->second);
  }
}

// union find
// 併合 -> ルートを片方のルートに結合させる
// 判定 -> ルートをたどって、同じ要素だったら同じグループ

int par[MAX_N];
int union_rank[MAX_N];

void init(int n) {
  for (int i = 0; i < n; i++) {
    par[i] = i;
    union_rank[i] = 0;
  }
}

int find(int x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) {
    return;
  }

  if (union_rank[x] < union_rank[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (union_rank[x] == union_rank[y]) {
      union_rank[x]++;
    }
  }
}

bool same(int x, int y) { return find(x) == find(y); }

int N, K;
const int MAX_K = 1000;
int T[MAX_K], X[MAX_K], Y[MAX_K];
int main() {
  N = 100;
  K = 100;
  init(N * 3);
  int ans = 0;
  for (int i = 0; i < K; i++) {
    int t = T[i];
    int x = X[i] - 1, y = Y[i] - 1;
    if (x < 0 || N <= x || y < 0 || N <= y) {
      ans++;
      continue;
    }

    if (t == 1) {
      if (same(x, y + N) || same(x, y + 2 * N)) {
        ans++;
      } else {
        unite(x, y);
        unite(x + N, y + N);
        unite(x + 2 * N, y + 2 * N);
      }
    } else {
      if (same(x, y) || same(x, y + 2 * N)) {
        ans++;
      } else {
        unite(x, y + N);
        unite(x + N, y + 2 * N);
        unite(x + 2 * N, y);
      }
    }
  }
}
