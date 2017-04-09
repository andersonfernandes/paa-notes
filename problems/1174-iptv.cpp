/*
  1174 - IP-TV <https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3615>
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> viii;
typedef vector<int> vi;
typedef map<string, int> mci;

viii adj_list;
priority_queue<ii> pq;
vi taken;
mci cities;
int index_count;

void process(int vtx) { 
  taken[vtx] = 1;
  
  for (int j = 0; j < (int) adj_list[vtx].size(); j++) {
    ii v = adj_list[vtx][j];
    if (!taken[v.first]) pq.push(ii(-v.second, -v.first));
  } 
} 

void insert_node(int x, int y, int c) {
  adj_list[x].push_back(ii(y, c));
  adj_list[y].push_back(ii(x, c));
} 

int insert_city(char* city_name) {
  mci::iterator it = cities.find(city_name);
  
  if(it != cities.end()) {
    return it->second;
  } else {
    cities.insert(make_pair(city_name, index_count++));
    return index_count-1;
  }
} 

int main() {
  int T;

  cin >> T;
  
  while (T > 0) {
    pq = priority_queue<ii>();
		adj_list.clear();
		taken.clear();
    cities.clear();
    index_count = 0;

    int M, N;
    scanf("%d %d", &M, &N);

		adj_list.resize(M+1);
		taken.resize(M+1, 0);

    for (int i = 0; i < N; ++i) {
      char B[8], E[8];
      int C;
      scanf("%s %s %d", B, E, &C);

      int b = insert_city(B);
      int e = insert_city(E);

      insert_node(b, e, C);
    }

    taken.assign(M, 0);
    process(0);
    int cost = 0;

    while (!pq.empty()) {
      ii front = pq.top(); pq.pop();
      int u = -front.second;
      int w = -front.first;

      if (!taken[u]) cost += w, process(u); 
    }

    cout << cost << endl;

    --T;
    if (T != 0) cout << endl; 
  }

}
