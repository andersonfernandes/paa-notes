/*
  11733 - Airports https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2833>
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vii> viii;

viii adj_list;
vi taken;
priority_queue<ii> pq;

void init(int n) {
  pq = priority_queue<ii>();
  adj_list.clear(); 
  adj_list.resize(n);
  taken.clear();
  taken.assign(n, 0);
}

void insert_node(int x, int y, int c) {
  adj_list[x].push_back(ii(y,c));
  adj_list[y].push_back(ii(x,c));
}

void process(int s) {    
  taken[s] = 1;

  for (int j = 0; j < (int)adj_list[s].size(); j++) {
    ii v = adj_list[s][j];

    if (!taken[v.first]) pq.push(ii(-v.second, -v.first));
  } 
} 

int mst(int s, int a) {
  int u, w, cost = 0;
  process(s);    

  while (!pq.empty()) { 
    ii front = pq.top(); pq.pop();
    u = -front.second, w = -front.first;  

    if (!taken[u]) {
      if (a <= w) {
				while (!pq.empty()) pq.pop();
				break;	
			} else cost += w;
      
      process(u); 
    } 
  }

  return cost;
}

int main() {
  int T;
  cin >> T;

  for (int i = 1; i <= T; i++) {
    int N, M, A;
    cin >> N >> M >> A;

    init(N);

    for (int j = 0; j < M; j++) {
      int X, Y, C;
      cin >> X >> Y >> C;

      insert_node(X-1, Y-1, C);
    }

    int ap = 0, cost = 0; 
    for (int j = 0; j < N; j++) {
      if (!taken[j]) {
        cost += mst(j, A) + A;
        ++ap;
			}
    }

    cout << "Case #" << i << ": " << cost << " " << ap << endl;
  }

	return 0;
}
