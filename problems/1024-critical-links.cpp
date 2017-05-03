/*
   1024 - Critical Links <https://www.thehuxley.com/problem/1024>
   */

#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adj_list;
vi color, discovery, low, parent;
vector<ii> critical_links;
int d_time = 0;

int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }

void dfs(int u)
{
	int child = 0;
	discovery[u] = low[u] = d_time++;
	color[u] = GRAY;

  for (int i = 0; i < adj_list[u].size(); i++) {
    int v = adj_list[u][i];

    if (color[v] == WHITE) {
      ++child;
      parent[v] = u;

      dfs(v);

      low[u] = min( low[u], low[v] );
      if (low[v] > discovery[u]) critical_links.push_back(ii( min(u, v), max(u, v) ));
    } else if (parent[u] != v) {
      low[u] = min( low[u], discovery[v] );
    }
  }

  color[u] = BLACK;
}

void init(int n) {
  adj_list.clear();
  adj_list.resize(n);
  critical_links.clear();

  discovery.clear();
  discovery.resize(n);
  low.clear();
  low.resize(n);
  parent.clear();
  parent.resize(n);
  color.clear();
  color.assign(n, WHITE);
}

int main() {
  int N;

  while (cin >> N) {
    init(N);

    for (int i = 0; i < N; i++) {
      int x, y, k;

      scanf("%d (%d)", &x, &k);

      for (int j = 0; j < k; j++) {
        cin >> y;

        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
      }
    }

    for (int u = 0; u < adj_list.size(); u++) {
      if (color[u] == WHITE) dfs(u);      
    }
    sort(critical_links.begin(), critical_links.end());

    cout << critical_links.size() << " critical links" << endl;
    for (int u = 0; u < critical_links.size(); u++) {
      cout << critical_links[u].first << " - " << critical_links[u].second << endl;
    }
    cout << endl;
  } 

  return 0;
}
