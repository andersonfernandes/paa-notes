/*
   1021 - Super Sales <https://www.thehuxley.com/problem/1021>
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector< vector<int> > matrix;

vector<ii> products;
matrix dp_cache;

int max(int a, int b) { return (a > b)? a : b; }

int dp(int i, int rc) {
  if (dp_cache[i][rc] != -1) return dp_cache[i][rc];

  if (i == products.size() || rc == 0) dp_cache[i][rc] = 0;
  else {
    int p = products[i].first, w = products[i].second;
    if (w > rc) dp_cache[i][rc] = dp(i+1, rc);
    else dp_cache[i][rc] = max(p + dp(i+1, rc - w), dp(i+1, rc));
  }

  return dp_cache[i][rc];
}

int max_value_for(int w) {
  dp_cache = matrix(products.size()+1, vector<int>(w+1, -1));
  
  return dp(0, w); 
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    int N, G, max_value = 0;
    cin >> N;

    products.clear();

    for (int j = 0; j < N; j++) {
      int P, W;

      cin >> P >> W;
      products.push_back(ii(P, W));       
    }

    cin >> G;

    for (int j = 0; j < G; j++) {
      int MW;
      cin >> MW;
      
      max_value += max_value_for(MW);
    }

    cout << max_value << endl;
  }
}
