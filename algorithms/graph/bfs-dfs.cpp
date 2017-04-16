/* Implementation of BFS and DFS algorithms using a non-weighted undirected Graph  */

#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adj_list;
vi colors;
vi distances;
vi predecessors;
queue<int> Q;

void init(int v) {
  adj_list.resize(v);
  colors.assign(v, WHITE);
  distances.assign(v, INT_MAX);
  predecessors.assign(v, -1);
}

void create_edge(int x, int y) {
  adj_list[x].push_back(y);
  adj_list[y].push_back(x);
}

void print_graph() {
  cout << endl;
  for (int i = 0; i < adj_list.size(); i++) {
    cout << i+1; 

    for (int j = 0; j < adj_list[i].size(); j++) {
      cout << " -> " << adj_list[i][j] + 1;
    }
    cout << " -> /" << endl;
  }
}

void print_bfs_node(int n) {
  printf("# %d | Distance from source %d | Predecessor %d\n", n+1, distances[n], predecessors[n]+1);
}

void bfs(int s) {
  colors[s] = GRAY; 
  distances[s] = 0;
  predecessors[s] = -1;

  Q.push(s);
  while (!Q.empty()) {
    int u = Q.front(); Q.pop();

    for (int i = 0; i < adj_list[u].size(); i++) {
      int v = adj_list[u][i];

      if (colors[v] == WHITE) {
        colors[v] = GRAY;
        distances[v] = distances[u] + 1;
        predecessors[v] = u;

        Q.push(v);
      } 
    }

    colors[u] = BLACK;
    print_bfs_node(u);
  }
}

int main() {
  int V, E;
  cin >> V >> E;

  init(V);

  for (int i = 0; i < E; i++) {
    int x, y;
    cin >> x >> y;

    create_edge(x-1, y-1);
  }

  cout << endl << "Starting BFS from vertex 1" << endl;

  bfs(0);

  return 0;
}
