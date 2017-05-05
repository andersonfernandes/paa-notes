/*
   1022 - Palíndromo <https://www.thehuxley.com/problem/1022>
*/

#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > matrix;

matrix dp_cache;

int max(int a, int b) { return (a > b) ? a : b;  }

int biggest_palindrome(string w) {
  dp_cache.clear();
  dp_cache = matrix(w.size(), vector<int>(w.size(), 0));

  for (int i = 0; i < w.size(); i++) dp_cache[i][i] = 1;

  for (int k = 2; k <= w.size(); k++) {
    for (int i = 0; i <= w.size()-k; i++) {
      int j = i + k - 1;

      if (w[i] == w[j] && k == 2) dp_cache[i][j] = 2;
      else if (w[i] == w[j]) dp_cache[i][j] = dp_cache[i+1][j-1] + 2;
      else dp_cache[i][j] = max( dp_cache[i][j-1], dp_cache[i+1][j] );
    }
  }

  return dp_cache[0][w.size()-1]; 
}

int main() {
  int T; string w;
  cin >> T;
  getchar();

  for (int i = 0; i < T; i++) {
    getline(cin, w);

    if (w == "") {
      cout << "0" << endl;
      continue;
    }

    cout << biggest_palindrome(w) << endl;
  }

  return 0;
}
