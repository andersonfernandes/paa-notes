/*
   11710 - Expensive subway https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2833 
   */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> viii;
typedef vector<int> vi;
typedef map<string, int> msi;

msi cities;
viii adj_list;
priority_queue<ii> pq;
vi taken;

void init(int n) {
  pq = priority_queue<ii>();
  adj_list.clear();
  adj_list.resize(n+1);
  taken.clear();
  taken.assign(n+1, 0);
  cities.clear();
}

void insert_node(int x, int y, int c) {
  adj_list[x].push_back(ii(y, c));
  adj_list[y].push_back(ii(x, c));
}

void process(int s) {    
  taken[s] = 1;

  for (int j = 0; j < (int)adj_list[s].size(); j++) {
    ii v = adj_list[s][j];

    if (!taken[v.first]) pq.push(ii(-v.second, -v.first));
  } 
} 

int mst(int s) {
  int u, w, cost = 0;
  process(s);    

  while (!pq.empty()) { 
    ii front = pq.top(); pq.pop();
    u = -front.second, w = -front.first;  

    if (!taken[u]) cost += w, process(u); 
  } 

  return cost;
} 

int main() {
  int s, c;
  while (cin >> s >> c, s+c != 0) {
    init(s);

    for (int i = 1; i <= s; i++) {
      char city_name[11];
      cin >> city_name;

      cities.insert(make_pair(city_name, i));
    }

    for (int i = 0; i < c; i++) {
      string x, y; int a;
      cin >> x >> y >> a;

      msi::iterator it_x = cities.find(x);
      msi::iterator it_y = cities.find(y);

      insert_node(it_x->second, it_y->second, a);      
    }

    string source; 
    cin >> source;

    msi::iterator it_source = cities.find(source);

    int cost = mst(it_source->second);

    for (int i = 1; i <= s; i++) {
      if (taken[i] == 0) cost = -1;
    }     

    if (cost == -1) cout << "Impossible" << endl;
    else cout << cost << endl;
  }

  return 0;
}
