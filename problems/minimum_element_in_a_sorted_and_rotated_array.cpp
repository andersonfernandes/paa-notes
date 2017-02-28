/*
  Minimum element in a sorted and rotated array <http://www.practice.geeksforgeeks.org/problem-page.php?pid=819>

  Análise: (Desconsiderando os tempos de pre-processamento dos dados na função main)

  O tempo de execução das chamadas recursivas da função find_min como T(n/2) e o restante da execução como um tempo constante k,
  temos como equação de recorrência:
          T(n) = T(n/2) + k

  Resolvendo essa equação, temos:
          T(n) = T(n/4 + k) + k = T(n/2^2) + 2k
          T(n) = T(n/8 + k) + 2k = T(n/2^3) + 3k
          T(n) = T(n/2^k) + kC

  Com n = 2^k, temos T(2^k) = T(2^k/2^k) = T(1) (tempo constante)
        T(1) = Ck (tempo costante)
  Percebe-se que log n = k (base 2), com n = 2^k

        T(n) = T(1) + C(log n)

  Desconsiderando as contantes o big-oh do algoritmo é: O(log n).

*/

#include <bits/stdc++.h>
using namespace std;

int find_min(vector<int> a, int li, int hi) {
  if (li == hi) return a[li];

  int mid = (li + hi) / 2;
  if (a[hi] < a[mid]) return find_min(a, mid+1, hi);
  else return find_min(a, li, mid);
}

int main() {
  int t;
  cin >> t;

  for(; t > 0; --t) {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    cout << find_min(a, 0, a.size()-1) << endl;
  }

  return 0;
}
