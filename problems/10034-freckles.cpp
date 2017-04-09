/*
   10034 - Freckles https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=975 
   */

#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> dd;
typedef pair<double, int> di;
typedef pair<int, double> id;
typedef vector<id> vid;
typedef vector<vid> viid;
typedef vector<int> vi;

vector<dd> freckles;
viid adj_list;
priority_queue<di> pq;
vi taken;

void init(int n) {
  pq = priority_queue<di>();
  freckles.resize(n);
  freckles.clear();

  adj_list.clear();
  adj_list.resize(n+1);

  taken.clear();
  taken.assign(n+1, 0);
}

void insert_node(int x, int y, double c) {
  adj_list[x].push_back(id(y, c));
  adj_list[y].push_back(id(x, c));
}

void process(int s) {    
  taken[s] = 1;

  for (int j = 0; j < (int)adj_list[s].size(); j++) {
    id v = adj_list[s][j];

    if (!taken[v.first]) pq.push(di(-v.second, -v.first));
  } 
} 

double mst(int s) {
  int u;
  double w, cost = 0.0;
  process(s);    

  while (!pq.empty()) { 
    di front = pq.top(); pq.pop();
    u = -front.second, w = -front.first;  

    if (!taken[u]) cost += w, process(u); 
  } 

  return cost;
}

int main() {
  int t;
  cin >> t;

  while (t) {
    int n;
    cin >> n;

    init(n);

    for (int i = 0; i < n; i++) {
      double x, y;
      cin >> x >> y;
      freckles[i] = dd(x, y);
    }

    for (int i = 1; i <= n; i++) {
      for (int j = i+1; j <= n; j++) {
        dd a = freckles[i-1];
        dd b = freckles[j-1];

        dd sub = dd(b.first - a.first, b.second - a.second );

        double c = sqrt(pow(sub.first, 2) + pow(sub.second, 2));
        insert_node(i, j, c);
      }
    }

    printf("%.2lf\n", mst(1));

    --t;
    if (t > 0) cout << endl;
  }

  return 0;
}
