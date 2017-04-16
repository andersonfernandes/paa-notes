/* Implementation of a weighted undirected Graph using a adjacency list */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vvii adj_list;
priority_queue<ii> pq;

void init(int v) {
  pq = priority_queue<ii>();
  adj_list.resize(v);
}

void create_edge(int x, int y, int w) {
  adj_list[x].push_back(ii(y, w));
  adj_list[y].push_back(ii(x, w));
}

void print_graph() {
  cout << endl;
  for (int i = 0; i < adj_list.size(); i++) {
    cout << i+1; 

    for (int j = 0; j < adj_list[i].size(); j++) {
      ii E = adj_list[i][j];
      cout << " -> [" << E.first+1 << ", " << E.second << "]";
    }
    cout << " -> /" << endl;
  }
}

int main() {
  /* V: Number of vertex
   * E: Number of edges */
  int V, E;
  cin >> V >> E;

  init(V);

  for (int i = 0; i < E; i++) {
    /* x, y: Vertex of the edge
     * w: Wight of the edge */
    int x, y, w;
    cin >> x >> y >> w;

    create_edge(x-1, y-1, w);
  }

  print_graph();

  return 0;
}
